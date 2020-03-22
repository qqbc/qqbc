# 连接QQBC测试网

## 目标

本节介绍如何搭建节点并连接QQBC测试网。

## 准备工作

* [安装QQBC软件](../../../00_install/index.md)。
* 确认`qqbcd`, `qqbccli`, and `kqqbcd`具有访问路径。如果用户使用Shell脚本构建QQBC，那么确认运行[安装脚本](../../../00_install/01_build-from-source/01_shell-scripts/03_install-qqbc-binaries.md)。
* 了解如何使用[qqbcd配置选项](../../02_usage/00_qqbcd-options.md)启用或禁用特定功能。

## 1节点搭建
### 1-1.配置步骤

设置生产节点，请遵循下列步骤：

  - [1. 创建目录](#1-mkdir-unproducer)
  - [2. 设置config.ini](#2-set-config.ini-unproducer)
  - [3. 获取genesis.json](#3-get-genesis.json-unproducer)
  - [4. 启动](#4-load-the-required-plugins-unproducer)

### 1-1-1. 创建目录

创建配置目录
```sh
mkdir -p ~/qqbcd/config

```
创建数据目录
```sh
mkdir -p ~/qqbcd/data
```
<span id="1-mkdir-unproducer"></span>

#### 1-1-2. 设置config.ini
首先获取官方网站获取[config.ini](https://github.com/qqbc/qqbc/blob/master/docs/01-user/04_testnet/config.ini),并将其放入 1-1-2的配置目录中,文件名修改为`config.ini`.

<span id="2-set-config.ini-unproducer"></span>

### 1-1-3. 获取genesis.json
首先获取官方网站获取[genesis.json](https://github.com/qqbc/qqbc/blob/master/docs/01-user/04_testnet/genesis.json),并将其放入 1-1-2的配置目录中.
<span id="3-get-genesis.json-unproducer"></span>

### 1-1-4. 启动
```sh
qqbcd --genesis-json ~/qqbcd/config/genesis.json --data-dir ~/qqbcd/data --config-dir ~/qqbcd/config
```
<span id="4-load-the-required-plugins-unproducer"></span>

