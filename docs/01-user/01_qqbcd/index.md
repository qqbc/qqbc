# Qqbcd
---

## 引言

`qqbcd`是运行在QQBC每个节点上的核心服务进程，配置用于处理智能合约、验证交易、生成包含经验证交易的区块，并确认区块将交易记录在区块链上。

## 安装

`qqbcd`随[QQBC软件](https://github.com/qqbc/qqbc/blob/master/README.md)一并提供。 安装`qqbcd`，详情参见“[QQBC软件安装](../00_install/index.md)”一章。

## 导航

`qqbcd`的配置和使用，参见如下章节：

* [使用](02_usage/index.md)L如何配置和使用`qqbcd`，节点的配置和环境设置。
* [插件](03_plugins/index.md)：如何使用插件，以及插件的配置选项，包括必需配置和可选配置。
* [重新运行](04_replays/index.md)：支持从快照或blocks.log日志文件重新运行区块链。
* [日志](06_logging/index.md)：如何配置和使用日志、日志程序、日志添加程序和日志记录等级。
* [升级指南](07_upgrade-guides/index.md)：QQBC版本和共识的升级指南。
* [故障排除](08_troubleshooting/index.md)：`qqbcd`常见故障的排除。

[[提示 | 访问节点]]
| 客户应用或智能合约在与区块链交互时，需要本地或远程访问运行`qqbcd`的节点。
