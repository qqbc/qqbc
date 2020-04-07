# 如何重播或重新同步完整历史？
---

## 目标

激励完整的区块链历史

## 准备工作

* 确保[安装区块链](../../../00_install/index.md)；
* 掌握[使用qqbcd](../../02_usage/index.md)；
* 了解[state_history_plugin插件](../../03_plugins/state_history_plugin/index.md)。

## 操作步骤

1. 获取单个区块的日志，置于`data/blocks`文件夹。或者获取创世文件，并使用`--genesis-json`选项；

2. 确保目录`data/state`尚不存在。否则使用`--replay-blockchain`选项；

3. 使用[`state_history_plugin`](index.md)列出的选项启动`qqbcd`。
