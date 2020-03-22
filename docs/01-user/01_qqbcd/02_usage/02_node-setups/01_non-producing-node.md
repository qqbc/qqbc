# 非生产节点设置
---

## 目标

本节介绍了如何在QQBC网络中设置非生产节点。非生产节点配置为不参与区块生成的节点，而是连接并同步QQBC区块链中的其它节点，通过支持一个或多个[Qqbcd插件](../../03_plugins/index.md)提供服务（不包含`producer_plugin`）。

## 准备工作

* [安装QQBC软件](../../../00_install/index.md)。
* 确认`qqbcd`, `qqbccli`, and `kqqbcd`具有访问路径。如果用户使用Shell脚本构建QQBC，那么确认运行[安装脚本](../../../00_install/01_build-from-source/01_shell-scripts/03_install-qqbc-binaries.md)。
* 了解如何使用[Qqbcd配置选项](../../02_usage/00_qqbcd-options.md)启用或禁用特定功能。

## 配置步骤

设置非生产节点过程很简单：

1. [设置网络对端](#1-set-peers)
2. [启用可用的插件](#2-enable-one-or-more-available-plugins)

<span id="1-set-peers"></span>
### 1. 设置网络对端

用户需要在config ini配置文件中指定一些网络对端。例如：

```console
# config.ini:

p2p-peer-address = 106.10.42.238:9876
```

也可用在运行`qqbcd`时，将网络对端指定为启动项。例如：


```sh
qqbcd ... --p2p-peer-address=106.10.42.238:9876
```

<span id="2-enable-one-or-more-available-plugins"></span>
### 2. 启用可用插件

所有可用的插件在“[Qqbcd插件](../../03_plugins/index.md)”一节列出并详细说明。在`qqbcd`启动时，将公开提供由其启用插件的功能。

例如，如果启用[`state_history_plugin`](../../03_plugins/state_history_plugin/index.md)，那么启动`qqbcd`的节点将成为一个提供完整的区块链历史记录的非生产节点。如果启用[`http_plugin`](../../03_plugins/http_plugin/index.md)，那么启动`qqbcd`的节点将成为一个公开提供QQBC RPC API的非生产节点。这样，用户可以通过在非生产节点上启用任意数量的现有插件，扩展非生产节点提供的基本功能。需注意的是，某些插件与其他插件具有依赖关系。因此在启用插件时，需要满足该插件的所有依赖性。
