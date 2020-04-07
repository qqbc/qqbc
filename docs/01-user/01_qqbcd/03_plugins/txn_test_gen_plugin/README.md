# txn\_test\_gen\_plugin README

该插件可用于为通证合约生成每秒指定数量的交易。为降低资源开销，该插件内部使用。

<!--
This general procedure was used when doing Dawn 3.0 performance testing as mentioned in https://github.com/QQBC/QQBC/issues/2078.-->

## 性能测试

下面给出如何使用`txn_test_gen_plugin`插件为节点生成每秒1000个交易

### 创建配置和数据目录

创建一个空目录，用于配置和数据。

`mkdir ~/QQBC.data`,

定义`logging.json`配置文件，定义不在控制台上输出调试信息（否则每个交易将会产生输出）。

```bash
cat << EOF > ~/QQBC.data/logging.json
{
  "includes": [],
  "appenders": [{
      "name": "consoleout",
      "type": "console",
      "args": {
        "stream": "std_out",
        "level_colors": [{
            "level": "debug",
            "color": "green"
          },{
            "level": "warn",
            "color": "brown"
          },{
            "level": "error",
            "color": "red"
          }
        ]
      },
      "enabled": true
    }
  ],

  "loggers": [{
      "name": "default",
      "level": "info",
      "enabled": true,
      "additivity": false,
      "appenders": [
        "consoleout"
      ]
    }
  ]
}
EOF
```

### 加载生产者

```bash
$ ./qqbcd -d ~/QQBC.data/producer_node --config-dir ~/QQBC.data/producer_node -l ~/QQBC.data/logging.json --http-server-address "" -p QQBC -e
```

### 加载生成交易的非生产者节点

```bash
$ ./qqbcd -d ~/QQBC.data/generator_node --config-dir ~/QQBC.data/generator_node -l ~/QQBC.data/logging.json --plugin qqbc::txn_test_gen_plugin --plugin qqbc::chain_api_plugin --p2p-peer-address localhost:9876 --p2p-listen-endpoint localhost:5555
```

### 在非生产者节点上创建钱包，斌设置bios合约。


```bash
$ ./qqbccli wallet create --to-console
$ ./qqbccli wallet import --private-key 5KQwrPbwdL6PhXujxW37FSSQZ1JiwsST4cqQzDeyXtP79zkvFD3
$ ./qqbccli set contract QQBC ~/QQBC/build.release/contracts/QQBC.bios/ 
```

### 启动txn_test_gen_plugin插件使用的账户

```bash
$ curl --data-binary '["QQBC", "5KQwrPbwdL6PhXujxW37FSSQZ1JiwsST4cqQzDeyXtP79zkvFD3"]' http://127.0.0.1:8888/v1/txn_test_gen/create_test_accounts
```

### 启动交易生成，在20毫秒内提交20个交易（即1000 TPS）

```bash
$ curl --data-binary '["", 20, 20]' http://127.0.0.1:8888/v1/txn_test_gen/start_generation
```

### 在生产者的控制台上输出

```bash
QQBC generated block 9b8b851d... #3219 @ 2018-04-25T16:07:47.000 with 500 trxs, lib: 3218
QQBC generated block e5b3cd5d... #3220 @ 2018-04-25T16:07:47.500 with 500 trxs, lib: 3219
QQBC generated block b243aeaa... #3221 @ 2018-04-25T16:07:48.000 with 500 trxs, lib: 3220
```

注意：控制台输出表明500毫秒生成一个区块，每个区块中有500个交易，合计1000 TPS。

<!--
### Demonstration
The following video provides a demo: https://vimeo.com/266585781-->