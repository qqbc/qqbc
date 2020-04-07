# 如何创建完整历史的可移植快照？
---

## 目标

创建自包含创世状态以来完整区块链状态历史的数据库。

## 准备工作

* 确保[安装区块链](../../../00_install/index.md)；
* 掌握[使用qqbcd](../../02_usage/index.md)；
* 了解[state_history_plugin插件](../../03_plugins/state_history_plugin/index.md)。

## 操作步骤


1. 在具有完整区块链状态历史的节点尚启用`producer_api_plugin`插件。

[[注意]]
| 设置防火墙禁止`http-server-address`访问，或是更改为`localhost:8888`以禁用远程访问。

2. 创建可移植快照
  
```sh
curl http://127.0.0.1:8888/v1/producer/create_snapshot | json_pp
```

3. 等待`qqbcd`在完成快照后生成数个区块。目的是使得区块历史文件比可移植快照至少多包含一个区块，并且使得`blocks.log`包含尚未形成不可逆的区块

[[注意]]
| 如果可移植快照中包括的区块产生分叉，那么快照将会失效。一旦发生这种情况，重新运行上述过程。

1. 停止`qqbcd`。

2. 对以下数据做备份：
   * 新创建的可移植快照（形式为`data/snapshots/snapshot-xxxxxxx.bin`）
   * 目录`data/state-history`中内容：
     * `chain_state_history.log`
     * `trace_history.log`
     * `chain_state_history.index`：可选。如果没有该文件，恢复过程将会延长。
     * `trace_history.index`：可选。如果没有该文件，恢复过程将会延长。
   * 可选：目录`data/blocks`中内容，不包括`data/blocks/reversible`。
