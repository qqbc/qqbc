## currency-stats子命令功能

获取指定通证的信息。

## 顺位项说明

`contract` _TEXT_ ：持有通证的合约名。

`symbol` _TEXT_：如果合约支持操作多种通证，指定通证名。

## 选项说明

该子命令不支持任何选项。

## 示例

获取QQBC.token合约中的SYS通证信息。 

```sh
qqbccli get currency stats QQBC.token SYS
```

```json
{
  "SYS": {
    "supply": "1000000000.0000 SYS",
    "max_supply": "10000000000.0000 SYS",
    "issuer": "QQBC"
  }
}
```
