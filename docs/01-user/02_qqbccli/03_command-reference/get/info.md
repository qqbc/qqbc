## info子命令功能

获取当前区块链信息。

## 顺位项说明

目前不支持任何顺位项。

## 选项说明

- `-h` - --help：输出帮助信息并退出。
  
## 示例


```sh
qqbccli get info
```

命令返回当前区块链信息。

```json
{
  "server_version": "7451e092",
  "head_block_num": 6980,
  "last_irreversible_block_num": 6963,
  "head_block_id": "00001b4490e32b84861230871bb1c25fb8ee777153f4f82c5f3e4ca2b9877712",
  "head_block_time": "2017-12-07T09:18:48",
  "head_block_producer": "initp",
  "recent_slots": "1111111111111111111111111111111111111111111111111111111111111111",
  "participation_rate": "1.00000000000000000"
}
```
