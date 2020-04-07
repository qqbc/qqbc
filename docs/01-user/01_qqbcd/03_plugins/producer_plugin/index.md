# producer_plugin插件

## 描述

`producer_plugin`插件为节点提供生成区块所需功能。

[[注意]]
| 生成区块还需做其它配置，参见“[配置区块生成节点](../../02_usage/02_node-setups/00_producing-node.md)”一节。

## 使用

```console
# config.ini
plugin = qqbc::producer_plugin [options]
```

```sh
# qqbcd startup params
qqbcd ... -- plugin qqbc::producer_plugin [options]
```

## 选项

下列选项可以从`qqbcd`命令行指定，也可以在`config.ini`文件中设置：

```console
Config Options for qqbc::producer_plugin:

  -e [ --enable-stale-production ]      Enable block production, even if the 
                                        chain is stale.
  -x [ --pause-on-startup ]             Start this node in a state where 
                                        production is paused
  --max-transaction-time arg (=30)      Limits the maximum time (in 
                                        milliseconds) that is allowed a pushed 
                                        transaction's code to execute before 
                                        being considered invalid
  --max-irreversible-block-age arg (=-1)
                                        Limits the maximum age (in seconds) of 
                                        the DPOS Irreversible Block for a chain
                                        this node will produce blocks on (use 
                                        negative value to indicate unlimited)
  --max-block-cpu-usage-threshold-us    Threshold of CPU block production to 
                                        consider block full; when within threshold 
                                        of max-block-cpu-usage block can be 
                                        produced immediately. Default value 5000
  --max-block-net-usage-threshold-bytes Threshold of NET block production to 
                                        consider block full; when within threshold
                                        of max-block-net-usage block can be produced
                                        immediately. Default value 1024
  -p [ --producer-name ] arg            ID of producer controlled by this node 
                                        (e.g. inita; may specify multiple 
                                        times)
  --private-key arg                     (DEPRECATED - Use signature-provider 
                                        instead) Tuple of [public key, WIF 
                                        private key] (may specify multiple 
                                        times)
  --signature-provider arg (=QQBC6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV=KEY:5KQwrPbwdL6PhXujxW37FSSQZ1JiwsST4cqQzDeyXtP79zkvFD3)
                                        Key=Value pairs in the form 
                                        <public-key>=<provider-spec>
                                        Where:
                                           <public-key>    is a string form of 
                                                           a vaild QQBC public
                                                           key
                                        
                                           <provider-spec> is a string in the 
                                                           form <provider-type>
                                                           :<data>
                                        
                                           <provider-type> is KEY, or kqqbcd                                        
                                           KEY:<data>      is a string form of 
                                                           a valid QQBC 
                                                           private key which 
                                                           maps to the provided
                                                           public key
                                        
                                           kqqbcd:<data>    is the URL where 
                                                           kqqbcd is available 
                                                           and the approptiate 
                                                           wallet(s) are 
                                                           unlocked
  --kqqbcd-provider-timeout arg (=5)     Limits the maximum time (in 
                                        milliseconds) that is allowed for 
                                        sending blocks to a kqqbcd provider for 
                                        signing
  --greylist-account arg                account that can not access to extended
                                        CPU/NET virtual resources
  --produce-time-offset-us arg (=0)     offset of non last block producing time
                                        in microseconds. Negative number 
                                        results in blocks to go out sooner, and
                                        positive number results in blocks to go
                                        out later
  --last-block-time-offset-us arg (=0)  offset of last block producing time in 
                                        microseconds. Negative number results 
                                        in blocks to go out sooner, and 
                                        positive number results in blocks to go
                                        out later
  --max-scheduled-transaction-time-per-block-ms arg (=100)
                                        Maximum wall-clock time, in 
                                        milliseconds, spent retiring scheduled 
                                        transactions in any block before 
                                        returning to normal transaction 
                                        processing.
  --incoming-defer-ratio arg (=1)       ratio between incoming transactions and 
                                        deferred transactions when both are 
                                        queued for execution                                        
                                                                            
  --producer-threads arg (=2)           Number of worker threads in producer 
                                        thread pool
  --snapshots-dir arg (="snapshots")    the location of the snapshots directory
                                        (absolute path or relative to 
                                        application data dir)
```

## 依赖关系

* [`chain_plugin`](../chain_plugin/index.md)

## 交易的优先级

如果`producer_plugin`插件存在待处理的事务队列，用户可以将一种事务类型的优先级赋予另一种事务类型的优先级。

下面的选项设置了传入事务与延迟事务间的比率：

```console
  --incoming-defer-ratio arg (=1)       
```

默认值为`1`，`producer`插件会为每个延迟的事务处理一个传入事务。 如果设置`arg`为`10`，那么`producer`插件将为每个延迟的事务处理10个传入事务。

如果`arg`设置为足够大的数字，那么插件将始终首先处理传入事务，直到传入事务的队列为空。相应地，如果`arg`设置为0，那么`producer`插件将首先处理延迟的事务队列。



### 加载依赖示例

```console
# config.ini
plugin = qqbc::chain_plugin [operations] [options]
```

```sh
# command-line
qqbcd ... --plugin qqbc::chain_plugin [operations] [options]
```

区块生成细节，参阅“[区块生成](10_block-producing-explained.md)”一文。
