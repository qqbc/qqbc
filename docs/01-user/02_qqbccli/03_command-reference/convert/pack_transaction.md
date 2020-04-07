## 命令功能

将签名JSON文本打包

## 顺位项说明选项

- `transaction` _TEXT_：字符串形式的签名JSNO文本。

## Options

- `-h,--help`：输出帮助信息并推出。
- `--pack-action-data`：打包交易内所有操作数据，需要与`qqbcd`交互。

## 使用


```sh
qqbccli convert pack_transaction '{
  "expiration": "2018-08-02T20:24:36",
  "ref_block_num": 14207,
  "ref_block_prefix": 1438248607,
  "max_net_usage_words": 0,
  "max_cpu_usage_ms": 0,
  "delay_sec": 0,
  "context_free_actions": [],
  "actions": [{
      "account": "QQBC",
      "name": "newaccount",
      "authorization": [{
          "actor": "QQBC",
          "permission": "active"
        }
      ],
      "data": "0000000000ea305500a6823403ea30550100000001000240cc0bf90a5656c8bb81f0eb86f49f89613c5cd988c018715d4646c6bd0ad3d8010000000100000001000240cc0bf90a5656c8bb81f0eb86f49f89613c5cd988c018715d4646c6bd0ad3d801000000"
    }
  ],
  "transaction_extensions": []
}'
```

## 输出

```json
{
  "signatures": [],
  "compression": "none",
  "packed_context_free_data": "",
  "packed_trx": "8468635b7f379feeb95500000000010000000000ea305500409e9a2264b89a010000000000ea305500000000a8ed3232660000000000ea305500a6823403ea30550100000001000240cc0bf90a5656c8bb81f0eb86f49f89613c5cd988c018715d4646c6bd0ad3d8010000000100000001000240cc0bf90a5656c8bb81f0eb86f49f89613c5cd988c018715d4646c6bd0ad3d80100000000"
}
```
