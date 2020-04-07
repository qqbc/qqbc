## wallet create_key子命令功能

在钱包中创建密钥对，无需用户手工导入密钥，例如`qqbccli create key`生成的密钥。默认情况下，创建密钥的类型是钱包最易于管理的，一般是K1密钥。命令也支持创建R1格式密钥对。


## 顺位项说明

`key_type` _TEXT_：指定创建密钥对类型，“K1”或“R1”。

## 选项说明

-n,--name TEXT=default。指定其中创建密钥对的钱包名。

## 使用

```sh
qqbccli wallet create_key K1
```

## 输出

```console
Created new private key with a public key of: "QQBC67xHKzQArkWZN6rKLCq7NLvaj8kurwxzRxoTVz6cgDJkiWdGug"
```
