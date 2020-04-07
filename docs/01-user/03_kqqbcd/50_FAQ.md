# kqqbcd FAQ
---

### `kqqbcd`是如何存储密钥对的？

`kqqbcd`在存储密钥对文件前，会在后台对密钥对做加密。根据不同的钱包实现方（例如Secure Clave或YubiHSM），将使用不同的加密算法。如果使用基于UNIX的标准文件系统，`kqqbcd`将使用CBC模式的256位AES加密。

<!--### 如何启用`kqqbcd`安全区域

要启用`kqqbcd`提供的安全区域特性，用户需要
To enable the secure enclave feature of `kqqbcd`, you need to sign a `kqqbcd` binary with a certificate provided with your Apple Developer Account. Be aware that there might be some constraints imposed by App Store when signing from a console application. Therefore, the signed binaries might need to be resigned every 7 days.-->
