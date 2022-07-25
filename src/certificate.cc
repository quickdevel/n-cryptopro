#include "certificate.h"

Napi::FunctionReference Certificate::constructor;

void Certificate::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Certificate", {
    InstanceMethod("getSubjectName", &Certificate::GetSubjectName),
    InstanceMethod("getIssuerName", &Certificate::GetIssuerName),
    InstanceMethod("getSerialNumber", &Certificate::GetSerialNumber),
    InstanceMethod("getValidPeriod", &Certificate::GetValidPeriod),
    InstanceMethod("verifyChain", &Certificate::VerifyChain),
    InstanceMethod("getProvider", &Certificate::GetProvider)
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Certificate", func);
}

Certificate::Certificate(const Napi::CallbackInfo& info) : Napi::ObjectWrap<Certificate>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->pContext_ = *info[0].As<Napi::External<PCCERT_CONTEXT>>().Data();
};

Certificate::~Certificate() {
  CertFreeCertificateContext(pContext_);
}

Napi::Value Certificate::FromContext(Napi::Env env, PCCERT_CONTEXT pCertContext) {
  return constructor.New({ Napi::External<PCCERT_CONTEXT>::New(env, &pCertContext) });
}

Napi::Value Certificate::FromBuffer(Napi::Env env, Napi::Buffer<uint8_t> nbBuffer) {
  PCCERT_CONTEXT pCertContext = CertCreateCertificateContext(X509_ASN_ENCODING | PKCS_7_ASN_ENCODING, nbBuffer.Data(), nbBuffer.Length());
  if (!pCertContext) {
    HandleError(env, "Error on CertCreateCertificateContext");
    return env.Undefined();
  }

  return FromContext(env, pCertContext);
}

Napi::Value Certificate::GetSubjectName(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  DWORD dwNameLength = CertGetNameString(pContext_, CERT_NAME_SIMPLE_DISPLAY_TYPE, 0, NULL, NULL, 0);

  std::string sName(dwNameLength, 0);
  CertGetNameString(pContext_, CERT_NAME_SIMPLE_DISPLAY_TYPE, 0, NULL, &sName[0], dwNameLength);

  return Napi::String::From(env, StringAcpToUtf8(sName));
}

Napi::Value Certificate::GetIssuerName(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  DWORD dwNameLength = CertGetNameString(pContext_, CERT_NAME_SIMPLE_DISPLAY_TYPE, CERT_NAME_ISSUER_FLAG, NULL, NULL, 0);

  std::string sName(dwNameLength, 0);
  CertGetNameString(pContext_, CERT_NAME_SIMPLE_DISPLAY_TYPE, CERT_NAME_ISSUER_FLAG, NULL, &sName[0], dwNameLength);

  return Napi::String::From(env, StringAcpToUtf8(sName));
}

Napi::Value Certificate::GetSerialNumber(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  return Napi::Buffer<uint8_t>::Copy(env, pContext_->pCertInfo->SerialNumber.pbData, pContext_->pCertInfo->SerialNumber.cbData);
}

Napi::Value Certificate::GetValidPeriod(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  
  Napi::Object nValidPeriod = Napi::Object::New(env);
  nValidPeriod.Set(Napi::String::New(env, "from"), Napi::Date::New(env, FileTimeToUnixTimeMs(pContext_->pCertInfo->NotBefore)));
  nValidPeriod.Set(Napi::String::New(env, "to"), Napi::Date::New(env, FileTimeToUnixTimeMs(pContext_->pCertInfo->NotAfter)));

  return nValidPeriod;
}

Napi::Value Certificate::VerifyChain(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  PCCERT_CHAIN_CONTEXT pChainContext = NULL;
  CERT_CHAIN_PARA certChainPara = { sizeof(certChainPara) };

  // TODO: Уточнить проверяемые условия
  // https://docs.cryptopro.ru/pkivalidator/reference/certverifycertificatechainpolicy-extension/samples
  CertGetCertificateChain(NULL, pContext_, NULL, NULL, &certChainPara, CERT_CHAIN_CACHE_END_CERT | CERT_CHAIN_REVOCATION_CHECK_CHAIN, NULL, &pChainContext);
  if (!pChainContext) {
    HandleError(env, "Error on CertGetCertificateChain");
    return env.Undefined();
  }

  CERT_CHAIN_POLICY_PARA certChainPolicyPara = { sizeof(certChainPolicyPara) };
  CERT_CHAIN_POLICY_STATUS certChainPolicyStatus = { sizeof(certChainPolicyStatus) };

  CertVerifyCertificateChainPolicy(NULL, pChainContext, &certChainPolicyPara, &certChainPolicyStatus);

  if (certChainPolicyStatus.dwError) {
    return Napi::Boolean::New(env, false);
  }
  
  return Napi::Boolean::New(env, true);
}

Napi::Value Certificate::GetProvider(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  return Provider::FromCertContext(env, pContext_);
}
