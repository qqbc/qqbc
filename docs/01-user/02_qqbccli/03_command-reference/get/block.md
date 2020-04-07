## block子命令功能

从区块链获取一个完全区块信息。

## 顺位项说明

- `block` _TEXT_：需检索区块的编号或ID。

## 选项说明

- `--header-state`：从分叉数据库获取区块头部状态。

## 示例


```sh
qqbccli get block 1
```
or
```sh
qqbccli get block 0000000130d70e94e0022fd2fa035cabb9e542c34ea27f572ac90b5a7aa3d891
```

输出区块对象内容示例为：

```json
{
  "timestamp": "2018-03-02T12:00:00.000",
  "producer": "",
  "confirmed": 1,
  "previous": "0000000000000000000000000000000000000000000000000000000000000000",
  "transaction_mroot": "0000000000000000000000000000000000000000000000000000000000000000",
  "action_mroot": "0000000000000000000000000000000000000000000000000000000000000000",
  "schedule_version": 0,
  "new_producers": null,
  "header_extensions": [],
  "producer_signature": "SIG_K1_111111111111111111111111111111111111111111111111111111111111111116uk5ne",
  "transactions": [],
  "block_extensions": [],
  "id": "0000000130d70e94e0022fd2fa035cabb9e542c34ea27f572ac90b5a7aa3d891",
  "block_num": 1,
  "ref_block_prefix": 3526296288
}
```
