# mongo_db_plugin插件

[[警告 | 禁用信息 ]]
| `mongo_db_plugin`插件已禁用，并不再维护。归档区块链数据可考虑使用[`state_history_plugin`](../state_history_plugin/index.md)和[`history-tools`](../state_history_plugin/index.md#history-tools)插件。

## 描述

区块链提供`qqbc::mongo_db_plugin`选项实现将区块链数据归档到MongoDB。推荐在非生产节点上使用该插件，因为一旦插入MongoDB失败，将关闭节点，并且该插件非常占用资源。如有可能，尽量设置单独`qqbcd`节点运行该插件。该插件设计为出错就关闭节点，是考虑到重启可解决所有连接性或MongoDB存在的问题，并且重启后无需重新同步或重播`qqbcd`。

## 重要提示

* 由`mongo_db_plugin`插件存储到MongoDB中的文档，如果包含为空的字段名或结构名，那么将存储为`empty_field_name`或`empty_struct_name`。
* 动作数据以原始字节形式存储在区块链上。为存储到MongoDB中，该插件将尝试使用帐户上相关的ABI将原始字节反序列化为扩展的`abi_def`形式。注意，对于合约中无效或丢失的ABI，相应动作数据以原始字节形式存储。例如，QQBC系统合约并没有为`onblock`动作提供ABI，因此该动作数据将以原始字节形式存储。
* `mongo_db_plugin`会降低重播和重新同步的性能，因为将区块数据转换为JSON并插入MongoDB中非常消耗资源。虽然插件使用工作者进程处理区块数据，但是并未显著改善重播和重新同步的性能。

## 建议

* 推荐对运行`mongo_db_plugin`插件的`qqbcd`实例的选项`--abi-serializer-max-time-ms`设置较大的值，因为默认的ABI序列化时间限制不足以序列化较大区块。
* 为避免可能的执行，应设置为只读模式。参见“[qqbcd读取模式](../../02_usage/05_qqbcd-implementation.md#qqbcd-read-modes)”一节内容。用于不能作为不可篡改的分叉数据依然将被记录，但是避免了交易处理和通告全链，降低了需存储的transaction_traces和action_traces追踪日志。

## 选项

下列选项可以从命令行指定，也可以配置在`config.ini`文件中：

```console
  -q [ --mongodb-queue-size ] arg (=256)
                                        The target queue size between qqbcd
                                        and MongoDB plugin thread.
  --mongodb-abi-cache-size              The maximum size of the abi cache for
                                        serializing data.
  --mongodb-wipe                        Required with --replay-blockchain,
                                        --hard-replay-blockchain, or
                                        --delete-all-blocks to wipe mongo
                                        db.This option required to prevent
                                        accidental wipe of mongo db. 
                                        Defaults to false.
  --mongodb-block-start arg (=0)        If specified then only abi data pushed
                                        to mongodb until specified block is
                                        reached.
  -m [ --mongodb-uri ] arg              MongoDB URI connection string, see:
                                        https://docs.mongodb.com/master/referen
                                        ce/connection-string/. If not specified
                                        then plugin is disabled. Default
                                        database 'QQBC' is used if not specified
                                        in URI. Example: mongodb://127.0.0.1:27
                                        017/QQBC
  --mongodb-update-via-block-num arg (=0)
                                        Update blocks/block_state with latest
                                        via block number so that duplicates are
                                        overwritten.                         
  --mongodb-store-blocks                Enables storing blocks in mongodb.
                                        Defaults to true.
  --mongodb-store-block-states          Enables storing block state in mongodb.
                                        Defaults to true.
  --mongodb-store-transactions          Enables storing transactions in mongodb.
                                        Defaults to true.
  --mongodb-store-transaction-traces    Enables storing transaction traces in                                             mongodb.
                                        Defaults to true.
  --mongodb-store-action-traces         Enables storing action traces in mongodb.
                                        Defaults to true.
  --mongodb-filter-on                   Mongodb: Track actions which match
                                        receiver:action:actor. Actor may be blank
                                        to include all. Receiver and Action may
                                        not be blank. Default is * include
                                        everything.
  --mongodb-filter-out                  Mongodb: Do not track actions which match
                                        receiver:action:actor. Action and Actor
                                        both blank excludes all from reciever.                                           Actor blank excludes all from
                                        reciever:action. Receiver may not be
                                        blank.
```

## 提示

* `--mongodb-store-*` 相关选项的缺省值均为true。
* `--mongodb-filter-*`选项当前仅应用于`action_traces`的采集。

## 过滤器示例

```console
mongodb-filter-out = qqbc:onblock:
mongodb-filter-out = gu2tembqgage::
mongodb-filter-out = blocktwitter:: 
```

[[警告]]]
| 一旦启用`mongo_db_plugin`插件，所用目标MongoDB将占用大量磁盘空间。如果启用所有采集，并且没有设置过滤器，那么MongoDB数据文件夹很快就会达到数百GB规模。推荐用户按需设置采集选项和过滤器，提高存储效率。

## 采集

* `accounts`：创建追踪的交易。无论是否设置选项`mongodb-store-action-traces=false`，均保持更新。
  * 当前仅局限于名称和ABI（如果账户具有合约ABI）；
  * 主要是内部使用，因为所存储ABI用于在合约中相关动作执行时，将动作数据转换为JSON存储。
  * 账户上ABI的无效动作，将导致动作数据无法转换为JSON存储，而是以原始字节方式存储。例如，`QQBC.system`合约并未对`onblock`动作提供ABI，因此所有`onblock`动作数据将以八进制存储，直至`QQBC.system`合约添加了`onblock` ABI。

* `action_traces` ：创建追踪的应用
  * `receipt` - action_trace和action_receipt。参见`qqbc::chain::action_receipt`；
  * `trx_id` - 交易ID；
  * `act` - 动作，参见`qqbc::chain::action`；
  * `elapsed` - 执行动作的时间（微秒）；
  * `console` - 动作在控制台数据。只有指定了`contracts-console = true`选项，才会产生输出。

* `block_states`：接收区块状态。
  * `block_num`；
  * `block_id`；
  * `block_header_state`：参见`qqbc::chain::block_header_state`；
  * `validated`；
  * `in_current_chain`；

* `blocks`：创建接收区块。
  * `block_num`
  * `block_id`
  * `block` ：已签名区块，参见`qqbc::chain::signed_block`；
  * `validated`：添加到不可篡改区块。
  * `in_current_chain`：添加到不可篡改区块。
  * `irreversible=true`：添加到不可篡改区块。

* `transaction_traces`：创建追踪的交易
  * 参见`chain::qqbc::transaction_trace`

* `transactions`：创建到已接收交易中，不包括在线动作。参见`qqbc::chain::signed_transaction`。除了`signed_transaction`数据，还存储下列数据：
  * `trx_id`：交易ID；
  * `irreversible=true`：添加到不可篡改区块；
  * `block_id` ：添加到不可篡改区块；
  * `block_num`：添加到不可篡改区块；
  * `signing_keys`；
  * `accepted`；
  * `implicit`；
  * `scheduled`。

* `account_controls`：创建追踪的交易。无论是否设置选项`mongodb-store-action-traces=false`，均保持更新。
  * `controlled_account`；
  * `controlling_permission`；
  * `controlling_account`。

 `/v1/history/get_controlled_acounts`对应于MongoDB中的`db.account_controls.find({"controlling_account":"hellozhangyi"}).pretty()`。

* `pub_keys`：创建追踪的交易。无论是否设置选项`mongodb-store-action-traces=false`，均保持更新。
  * `account`；
  * `permission`；
  * `public_key`。

## 示例

等同于MongoDB`/v1/history/get_key_accounts`的RPC API端点：

```console
db.pub_keys.find({"public_key":"QQBC7EarnUhcyYqmdnPon8rm7mBCTnBoot6o7fE2WzjvEX2TdggbL3"}).pretty()
```

## 依赖关系

* [`chain_plugin`](../chain_plugin/index.md)
* [`history_plugin`](../history_plugin/index.md)
