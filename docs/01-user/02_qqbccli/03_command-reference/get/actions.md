## actions子命令功能

根据认证和接收情况，获取特定账户的所有操作。

## 顺位项说明：

- `account_name` _TEXT_ ：查询账户名（必需项）
- `pos` _INT_：账户操作的序列号（可选项）
- `offset` _INT_：偏移量为正时，输出[pos, pos + offset]；偏移量为负时，输出[pos - offset, pos]。


## 选项说明

- `-j,--json` ：输出完整JSON。
- `--full` ：操作输出不做截断处理
- `--pretty`： - 完整操作JSON的美化输出。
- `--console` ：在控制台输出操作生成内容。

## 示例

检索并保存QQBC.token合约的ABI。

```sh
qqbccli get actions QQBC.token
```
```console
#  seq  when                              contract::action => receiver      trx id...   args
================================================================================================================
#  976   2018-06-01T19:54:05.000     QQBC.token::transfer => QQBC.token   1d1fe154... {"from":"userae","to":"useraa","quantity":"0.000...
#  977   2018-06-01T19:54:05.000     QQBC.token::transfer => QQBC.token   a0c9e5bc... {"from":"userab","to":"useraa","quantity":"0.000...
#  978   2018-06-01T19:54:05.000     QQBC.token::transfer => QQBC.token   3749d0d1... {"from":"userab","to":"userah","quantity":"0.000...
#  979   2018-06-01T19:54:05.000     QQBC.token::transfer => QQBC.token   dda205b0... {"from":"userai","to":"useraj","quantity":"0.000...
#  980   2018-06-01T19:54:05.000     QQBC.token::transfer => QQBC.token   14089e9b... {"from":"userab","to":"userae","quantity":"0.000...
#  981   2018-06-01T19:54:05.000     QQBC.token::transfer => QQBC.token   6882cefc... {"from":"useraj","to":"userab","quantity":"0.000...
...
```
