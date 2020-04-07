## sign命令功能

签名交易

## 使用

```sh
qqbccli sign [OPTIONS] transaction
```

## 顺位项说明

- `transaction` _TEXT_ ：指定需签名交易，可以是JSON字符串，也可以是文件名。

## 选项说明

- `-k,--private-key` _TEXT_ ：交易签名使用的私钥。
- `--public-key` _TEXT_ ：提请`kqqbcd`使用指定公钥对应的私钥进行签名。
- `-c,--chain-id` _TEXT_ ：签名交易使用的链ID。
- `-p,--push-transaction` ：签名后将交易推送到链上。
