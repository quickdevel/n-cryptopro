[n-cryptopro](README.md) / Exports

# n-cryptopro

## Table of contents

### Namespaces

- [CAdES](modules/CAdES.md)
- [XAdES](modules/XAdES.md)

### Interfaces

- [Certificate](interfaces/Certificate.md)
- [Provider](interfaces/Provider.md)
- [SignOptions](interfaces/SignOptions.md)
- [VerifyAttachedSignatureResult](interfaces/VerifyAttachedSignatureResult.md)
- [VerifySignatureResult](interfaces/VerifySignatureResult.md)

### Variables

- [CALG\_GR3411](modules.md#calg_gr3411)
- [CALG\_GR3411\_2012\_256](modules.md#calg_gr3411_2012_256)
- [CALG\_GR3411\_2012\_512](modules.md#calg_gr3411_2012_512)
- [PROV\_GOST\_2001\_DH](modules.md#prov_gost_2001_dh)
- [PROV\_GOST\_2012\_256](modules.md#prov_gost_2012_256)
- [PROV\_GOST\_2012\_512](modules.md#prov_gost_2012_512)

### Functions

- [decryptMessage](modules.md#decryptmessage)
- [encryptMessage](modules.md#encryptmessage)
- [getCertificateFromBuffer](modules.md#getcertificatefrombuffer)
- [getCertificates](modules.md#getcertificates)
- [hash](modules.md#hash)
- [signHash](modules.md#signhash)
- [signMessage](modules.md#signmessage)
- [verifyDetachedMessageSignature](modules.md#verifydetachedmessagesignature)
- [verifyHashSignature](modules.md#verifyhashsignature)
- [verifyMessageSignature](modules.md#verifymessagesignature)

## Variables

### CALG\_GR3411

• `Const` **CALG\_GR3411**: `number`

Алгоритм хэширования в соответствии с ГОСТ Р 34.11-94

___

### CALG\_GR3411\_2012\_256

• `Const` **CALG\_GR3411\_2012\_256**: `number`

Алгоритм хэширования в соответствии с ГОСТ Р 34.11-2012, длина выхода 256 бит

___

### CALG\_GR3411\_2012\_512

• `Const` **CALG\_GR3411\_2012\_512**: `number`

Алгоритм хэширования в соответствии с ГОСТ Р 34.11-2012, длина выхода 512 бит

___

### PROV\_GOST\_2001\_DH

• `Const` **PROV\_GOST\_2001\_DH**: `number`

Провайдер типа PROV_GOST_2001_DH создает ключи алгоритма ГОСТ Р 34.10-2001

___

### PROV\_GOST\_2012\_256

• `Const` **PROV\_GOST\_2012\_256**: `number`

Провайдер типа PROV_GOST_2012_256 создает ключи алгоритма ГОСТ Р 34.10-2012 длины 256 бит (длина открытого ключа 512 бит)

___

### PROV\_GOST\_2012\_512

• `Const` **PROV\_GOST\_2012\_512**: `number`

Провайдер типа PROV_GOST_2012_512 создает ключи алгоритма ГОСТ Р 34.10-2012 длины 512 бит (длина открытого ключа 1024 бита)

## Functions

### decryptMessage

▸ **decryptMessage**(`message`): `Buffer`

Расшифровка сообщения

#### Parameters

| Name | Type | Description |
| :------ | :------ | :------ |
| `message` | `Buffer` | Буфер с сообщением |

#### Returns

`Buffer`

___

### encryptMessage

▸ **encryptMessage**(`certificate`, `message`): `Buffer`

Шифрование сообщения

#### Parameters

| Name | Type | Description |
| :------ | :------ | :------ |
| `certificate` | [`Certificate`](interfaces/Certificate.md) | Сертификат |
| `message` | `Buffer` | Буфер с зашифрованым сообщением |

#### Returns

`Buffer`

___

### getCertificateFromBuffer

▸ **getCertificateFromBuffer**(`buffer`): [`Certificate`](interfaces/Certificate.md)

Получение сертификата из буфера

#### Parameters

| Name | Type | Description |
| :------ | :------ | :------ |
| `buffer` | `Buffer` | Буфер с сертификатом в формате X.509 / PKCS #7 |

#### Returns

[`Certificate`](interfaces/Certificate.md)

___

### getCertificates

▸ **getCertificates**(`storeName`): [`Certificate`](interfaces/Certificate.md)[]

Получение списка сертификатов из хранилища сертификатов

#### Parameters

| Name | Type | Description |
| :------ | :------ | :------ |
| `storeName` | `string` | Название хранилища сертификатов (напр. "My") |

#### Returns

[`Certificate`](interfaces/Certificate.md)[]

___

### hash

▸ **hash**(`algorithm`, `data`): `Buffer`

Вычисление хэша для данных

#### Parameters

| Name | Type | Description |
| :------ | :------ | :------ |
| `algorithm` | `number` | Алгоритм (напр. CryptoPro.CALG_GR3411) |
| `data` | `Buffer` | Буфер с данными |

#### Returns

`Buffer`

___

### signHash

▸ **signHash**(`certificate`, `algorithm`, `hash`): `Buffer`

Подпись хэша

#### Parameters

| Name | Type | Description |
| :------ | :------ | :------ |
| `certificate` | [`Certificate`](interfaces/Certificate.md) | Сертификат |
| `algorithm` | `number` | Алгоритм (напр. CryptoPro.CALG_GR3411) |
| `hash` | `Buffer` | Буфер с хэшем |

#### Returns

`Buffer`

___

### signMessage

▸ **signMessage**(`certificate`, `message`, `options`): `Buffer`

Подписание сообщения

#### Parameters

| Name | Type | Description |
| :------ | :------ | :------ |
| `certificate` | [`Certificate`](interfaces/Certificate.md) | Сертификат |
| `message` | `Buffer` | Буфер с сообщением |
| `options` | `object` | Доп. параметры |

#### Returns

`Buffer`

___

### verifyDetachedMessageSignature

▸ **verifyDetachedMessageSignature**(`signature`, `message`): [`VerifySignatureResult`](interfaces/VerifySignatureResult.md)

Проверка подписи сообщения (detached)

#### Parameters

| Name | Type | Description |
| :------ | :------ | :------ |
| `signature` | `Buffer` | Буфер с подписью |
| `message` | `Buffer` | Буфер с сообщением |

#### Returns

[`VerifySignatureResult`](interfaces/VerifySignatureResult.md)

___

### verifyHashSignature

▸ **verifyHashSignature**(`certificate`, `algorithm`, `hash`, `signature`): `boolean`

Проверка подписи хэша

#### Parameters

| Name | Type | Description |
| :------ | :------ | :------ |
| `certificate` | [`Certificate`](interfaces/Certificate.md) | Сертификат |
| `algorithm` | `number` | Алгоритм (напр. CryptoPro.CALG_GR3411) |
| `hash` | `Buffer` | Буфер с хэшем |
| `signature` | `Buffer` | Буфер с подписью |

#### Returns

`boolean`

___

### verifyMessageSignature

▸ **verifyMessageSignature**(`message`): [`VerifyAttachedSignatureResult`](interfaces/VerifyAttachedSignatureResult.md)

Проверка подписи сообщения (attached)

#### Parameters

| Name | Type | Description |
| :------ | :------ | :------ |
| `message` | `Buffer` | Буфер с подписаным сообщением |

#### Returns

[`VerifyAttachedSignatureResult`](interfaces/VerifyAttachedSignatureResult.md)
