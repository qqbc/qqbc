## 目标

将交易推送到网络。


## 准备工作

* 安装了适用版本的`qqbccli`。

* 理解以下概念：
  * 交易；
  * 如何生成JSON格式的验证交易。


## 操作步骤：


* 创建包含验证交易的JSON文件，部分展示如下：

```JSON
{
  "expiration": "2019-08-01T07:15:49",
  "ref_block_num": 34881,
  "ref_block_prefix": 2972818865,
  "max_net_usage_words": 0,
  "max_cpu_usage_ms": 0,
  "delay_sec": 0,
  "context_free_actions": [],
  "actions": [{
      "account": "QQBC.token",
      "name": "transfer",
      "authorization": [{
          "actor": "han",
          "permission": "active"
        }
      ],
      "data": "000000000000a6690000000000ea305501000000000000000453595300000000016d"
    }
  ],
  "transaction_extensions": [],
  "context_free_data": []
}
```

* 也可在`data`使用JSON明文创建。

[[提示]]
| 如果使用明文`data`域，那么`qqbccli`需要使用`qqbcd` API获取所需API的拷贝。该操作需要`qqbcd`的额外性能开销。

```JSON
{
  "expiration": "2019-08-01T07:15:49",
  "ref_block_num": 34881,
  "ref_block_prefix": 2972818865,
  "max_net_usage_words": 0,
  "max_cpu_usage_ms": 0,
  "delay_sec": 0,
  "context_free_actions": [],
  "actions": [{
      "account": "QQBC.token",
      "name": "transfer",
      "authorization": [{
          "actor": "han",
          "permission": "active"
        }
      ],
      "data": {
        "from": "han",
        "to": "QQBC",
        "quantity": "0.0001 SYS",
        "memo": "m"
      }
    }
  ],
  "transaction_extensions": [],
  "context_free_data": []
}
```

* 执行以下命令：

```sh
qqbccli push transaction TRX_FILE.json
```

* 从JSON提交交易：

```sh
qqbccli push transaction JSON
```

<!---
Link to Push Action API
-->