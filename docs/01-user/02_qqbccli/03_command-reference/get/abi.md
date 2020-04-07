## abi子命令功能

获取账户的ABI。

## 顺位项说明

- `name` _TEXT_：需检索abi信息的账户名。

## 选项说明

- `-f,--file` _TEXT_：合约abi写入的文件名，替代输出到终端。

## 示例：

检索QQBC.token合约并保存结果

```sh
qqbccli get abi QQBC.token -f QQBC.token.abi
```
```console
saving abi to QQBC.token.abi
```
