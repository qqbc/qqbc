# 生产节点设置
---

[[提示 | 需要系统合约]]
| 下面指令假定用户需要区块链网络上启动在加载系统合约的生产节点。指令并不支持使用原生功能的默认开发节点，或是没有加载系统合约的节点。

## 目标

本节介绍如何在QQBC网络中设置生产节点。正如名称所示，生产节点配置用于在基于QQBC的区块链中生成区块。其功能是通过`producer_plugin`等[qqbcd插件](../../03_plugins/index.md)实现的。


## 准备工作

* [安装QQBC软件](../../../00_install/index.md)。
* 确认`qqbcd`, `qqbccli`, and `kqqbcd`具有访问路径。如果用户使用Shell脚本构建QQBC，那么确认运行[安装脚本](../../../00_install/01_build-from-source/01_shell-scripts/03_install-qqbc-binaries.md)。
* 了解如何使用[qqbcd配置选项](../../02_usage/00_qqbcd-options.md)启用或禁用特定功能。

## 配置步骤

设置生产节点，请遵循下列步骤：

  - [1. 注册用户账户为生产者](#1-register-your-account-as-a-producer)
  - [2. 设置生产者名称](#2-set-producer-name)
  - [3. 设置生产者的签名提供方](#3-set-the-producers-signature-provider)
  - [4. 定义P2P网络对端](#4-define-a-peers-list)
  - [5. 加载所需插件](#5-load-the-required-plugins)

<span id="1-register-your-account-as-a-producer"></span>
### 1. 注册用户账户为生产者

用户账户要成为生产者，需要完成注册。命令如下：


```sh
qqbccli system regproducer accountname1 EOS1234534... http://producer.site Antarctica
```

<span id="2-set-producer-name"></span>
### 2. 设置生产者名称

设置`config.ini`配置文件中的`producer-name`选项为用户名，命令如下：

```console
# config.ini:

# ID of producer controlled by this node (e.g. inita; may specify multiple times) (eosio::producer_plugin)
producer-name = youraccount
```

<span id="3-set-the-producers-signature-provider"></span>
### 3. 设置生产者的签名提供方

用户需要设置生产者的私钥。公钥需要指定上面配置密钥的提供方信息。

配置项`signature-provider`定义包括如下三项：
* `public-key`：以字符串形式的可用QQBC公钥。
* `provider-spec`：字符串，形式为<provider-type>:<data>
* `provider-type`：KEY或KQQBCD


#### 使用KEY：

```console
# config.ini:

signature-provider = PUBLIC_SIGNING_KEY=KEY:PRIVATE_SIGNING_KEY

//Example
//signature-provider = EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV=KEY:5KQwrPbwdL6PhXujxW37FSSQZ1JiwsST4cqQzDeyXtP79zkvFD3
```

#### 使用KQQBCD:

用户可使用`kqqbcd`，避免完全指定密钥。

```console
# config.ini:

signature-provider = KQQBCD:<data>   

//Example
//EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV=KQQBCD:https://127.0.0.1:88888
```

<span id="4-define-a-peers-list"></span>
### 4. 定义P2P网络对端

```console
# config.ini:

# 缺省p2p端口为9876
p2p-peer-address = 123.255.78.9:9876
```

<span id="5-load-the-required-plugins"></span>
### 5. 加载所需插件

在用户节点的[config.ini](../index.md)配置文件中，确认加载或添加了如下插件：

```console
# config.ini:

plugin = eosio::chain_plugin
plugin = eosio::producer_plugin
```
