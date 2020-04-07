## currency-balance子命令功能

获取指定账户持有的标准通证信息。

## 顺位项说明

`contract` _TEXT_ ：指定操作通证的账户名。

`account` _TEXT_：需查询的账户名。

`symbol` _TEXT_ ：如果账户支持持有多种通证，指定通证代码。

## 选项说明

该子命令不支持任何选项。

## 示例

从QQBC.token合约获取账户QQBC持有的SYS通证情况。 

```sh
qqbccli get currency balance QQBC.token QQBC SYS
```

```console
999999920.0000 SYS
```
