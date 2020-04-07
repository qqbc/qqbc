## table子命令功能

获取数据表的内容。

## 顺位项说明

`contract` _TEXT_：数据表所属合约名。

`scope` _TEXT_：合约内查找数据表的范围。

`table` _TEXT_ ：合约ABI指定的数据表名

## 选项说明

`-b,--binary` _UINT_：返回二进制形式的值，而非以JSON表示的ABI。

`-l,--limit` _UINT_ ：返回的最大行数。

`-k,--key` _TEXT_：由ABI定义的索引键值，默认为主键。

`-L,--lower` _TEXT_：JSON格式表示的键值下限值，默认为第一行。

`-U,--upper` _TEXT_：JSON格式表示的键值上限值，默认为最后一行。

## 示例

从QQBC.token合约的QQBC账户数据表中获取数据。

```sh
qqbccli get table QQBC.token QQBC accounts
```
```json
{
  "rows": [{
      "balance": "999999920.0000 SYS"
    }
  ],
  "more": false
}
```
