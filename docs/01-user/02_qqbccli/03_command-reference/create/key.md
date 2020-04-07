## key子命令功能

创建新的密钥对，并输出公钥和私钥内容。

## 使用

```console
Usage: qqbccli create key [OPTIONS]

Options:
  -h,--help                   Print this help message and exit
  --r1                        Generate a key using the R1 curve (iPhone), instead of the K1 curve (Bitcoin)
  -f,--file TEXT              Name of file to write private/public key output to. (Must be set, unless "--to-console" is passed
  --to-console                Print private/public keys to console.
```

## 命令

```sh
qqbccli create key -f passwd
```

## 输出

```console
Private key: 5KCkcSxYKZfh5Cr8CCunS2PiUKzNZLhtfBjudaUnad3PDargFQo
Public key: QQBC5uHeBsURAT6bBXNtvwKtWaiDSDJSdSmc96rHVws5M1qqVCkAm6
```
