[n-cryptopro](../README.md) / [Exports](../modules.md) / XAdES

# Namespace: XAdES

## Table of contents

### Interfaces

- [XAdESSignOptions](../interfaces/XAdES.XAdESSignOptions.md)
- [XAdESVerifySignatureOptions](../interfaces/XAdES.XAdESVerifySignatureOptions.md)
- [XAdESVerifySignatureResult](../interfaces/XAdES.XAdESVerifySignatureResult.md)

### Variables

- [XADES\_BES](XAdES.md#xades_bes)
- [XADES\_T](XAdES.md#xades_t)
- [XADES\_XMLDSIG](XAdES.md#xades_xmldsig)
- [XADES\_X\_LONG\_TYPE\_1](XAdES.md#xades_x_long_type_1)

### Functions

- [signMessage](XAdES.md#signmessage)
- [verifyMessageSignature](XAdES.md#verifymessagesignature)

## Variables

### XADES\_BES

• `Const` **XADES\_BES**: `number`

Тип сообщения XAdES BES

___

### XADES\_T

• `Const` **XADES\_T**: `number`

Тип сообщения XAdES-T

___

### XADES\_XMLDSIG

• `Const` **XADES\_XMLDSIG**: `number`

Тип сообщения XMLDSIG

___

### XADES\_X\_LONG\_TYPE\_1

• `Const` **XADES\_X\_LONG\_TYPE\_1**: `number`

Тип сообщения XAdES-X Long Type 1

## Functions

### signMessage

▸ **signMessage**(`certificate`, `message`, `options?`): `Buffer`

Подписание сообщения

#### Parameters

| Name | Type | Description |
| :------ | :------ | :------ |
| `certificate` | [`Certificate`](../interfaces/Certificate.md) | Сертификат |
| `message` | `Buffer` | Буфер с сообщением |
| `options?` | [`XAdESSignOptions`](../interfaces/XAdES.XAdESSignOptions.md) | Доп. параметры |

#### Returns

`Buffer`

___

### verifyMessageSignature

▸ **verifyMessageSignature**(`message`, `options?`): [`XAdESVerifySignatureResult`](../interfaces/XAdES.XAdESVerifySignatureResult.md)[]

Проверка подписи сообщения

#### Parameters

| Name | Type | Description |
| :------ | :------ | :------ |
| `message` | `Buffer` | Буфер с подписаным сообщением |
| `options?` | [`XAdESVerifySignatureOptions`](../interfaces/XAdES.XAdESVerifySignatureOptions.md) | Доп. параметры |

#### Returns

[`XAdESVerifySignatureResult`](../interfaces/XAdES.XAdESVerifySignatureResult.md)[]
