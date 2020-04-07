# 如何存储完整历史的可移植快照？
---

## 目标

存储现有的完整历史可移植快照，使得节点在区块链上成为活动状态。


## 准备工作

* 确保[安装区块链](../../../00_install/index.md)；
* 掌握[使用qqbcd](../../02_usage/index.md)；
* 了解[state_history_plugin插件](../../03_plugins/state_history_plugin/index.md)。

## 操作步骤



1. 获取如下数据：
   * 获取可移植快照（形式为`data/snapshots/snapshot-xxxxxxx.bin`）；
   * 获取目录`data/state-history`内容；
   * 可选：包含快照记录区块的区块日志，但不包括目录`data/blocks/reversible`。

2. 确认目标`data/state`不存在；

3. 使用`--snapshot`选项和[`state_history_plugin`](#index.md)给出的选项启动`qqbcd`。

4. 在`qqbcd`接收到至少一个区块前，不要关闭整个区块链网络，否则会导致`qqbcd`无法正常重启。

## 注意事项

如果`qqbcd`没有成功从区块链接收区块，那么尝试使用`net_api_plugin`插件。运行命令`qqbccli net disconnect` 和`qqbccli net connect`连接报超时错误的节点。

[[注意：慎用`net_api_plugin`插件]]
| 设置防火墙阻拦`http-server-address`，或是更改服务地址为`localhost:8888`，禁止远端访问。