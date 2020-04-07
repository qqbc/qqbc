# 如何不考虑过往区块链历史而快速启动？
---

## 目标

该操作过程将记录当前区块链状态和完整历史，并不记录本地链的过往历史数据。


## 准备工作

* 确保[安装区块链](../../../00_install/index.md)；
* 掌握[使用qqbcd](../../02_usage/index.md)；
* 了解[state_history_plugin插件](../../03_plugins/state_history_plugin/index.md)。

## 操作步骤

1. 获取如下数据：
   * 可移植快照（通常形式为`data/snapshots/snapshot-xxxxxxx.bin`）；
   * 可选项：区块日志，其中包括记录快照的区块。

2. 确认目录`data/state`尚不存在。

3. 使用`--snapshot`选项和[`state_history_plugin`](#index.md)给出的选项启动`qqbcd`。

4. 在日志中查找记录“`Placing initial state in block n` ”，其中`n`是起始区块。

5. 使用`--fpg-create`、`--fill-skip-to n`和`--fill-trim`选项指定存储管理（例如PostgreSQL）), 其中`n` 是第4步获取的起始区块高度。

6. 在`qqbcd`接收到至少一个区块前，不要关闭整个区块链网络，否则会导致`qqbcd`无法正常重启。

## 注意事项

如果`qqbcd`没有成功从区块链接收区块，那么尝试使用`net_api_plugin`插件。运行命令`qqbccli net disconnect` 和`qqbccli net connect`连接报超时错误的节点。

[[注意：慎用`net_api_plugin`插件]]
| 设置防火墙阻拦`http-server-address`，或是更改服务地址为`localhost:8888`，禁止远端访问。

[[提示]]
| 如果存储管理在插件启动后尚未提供服务，那么需使用`--fill-trim`选项。第一次运行时，只需使用`--fpg-create` 和`--fill-skip-to`选项。

[[提示]]
| 对于一定规模的区块链，JavaScript过程无法处理大量增量创建记录，需使用64位C++过程处理大规模记录。 选项`fill-pg`和`fill-lmdb`可在写入数据库前将单个大记录切分为多个小记录。
