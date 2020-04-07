# state_history_plugin插件

## 描述

`state_history_plugin`插件用于获取区块链状态的历史数据。插件从其它连接节点上获取区块链数据，并缓存数据到文件中。插件以socket方式监听，基于`qqbcd`启动时的插件选项设置，实现应用连接并送回区块链数据。

## 使用

```console
# config.ini
plugin = qqbc::state_history_plugin
[options]
```

```sh
# command-line
qqbcd ... --plugin qqbc::state_history_plugin [operations] [options]
```

## 操作

下面选项只能在`qqbcd`命令行指定：

```console
Command Line Options for qqbc::state_history_plugin:

  --delete-state-history                clear state history files
```

## 选项

下列选项可以从`qqbcd`命令行指定，也可以在`config.ini`文件中设置：

```console
Config Options for qqbc::state_history_plugin:

  --state-history-dir arg (="state-history")
                                        the location of the state-history 
                                        directory (absolute path or relative to
                                        application data dir)
  --trace-history                       enable trace history
  --chain-state-history                 enable chain state history
  --state-history-endpoint arg (=127.0.0.1:8080)
                                        the endpoint upon which to listen for 
                                        incoming connections. Caution: only 
                                        expose this port to your internal 
                                        network.
  --trace-history-debug-mode            enable debug mode for trace history
```

## 示例

<!--### history-tools

  * [Source code](https://github.com/QQBC/history-tools/)
  * [Documentation](https://QQBC.github.io/history-tools/)-->

## 依赖关系

* [`chain_plugin`](../chain_plugin/index.md)

### 加载依赖示例

```console
# config.ini
plugin = qqbc::chain_plugin --disable-replay-opts
```

```sh
# command-line
qqbcd ... --plugin qqbc::chain_plugin --disable-replay-opts
```

## 操作指南

* [如何不考虑过往区块链历史而快速启动插件？](10_how-to-fast-start-without-old-history.md)
* [如何重播或重新同步完整历史？](20_how-to-replay-or-resync-with-full-history.md)
* [如何创建完整历史的可移植快照？](30_how-to-create-snapshot-with-full-history.md)
* [如何存储完整历史的可移植快照？](40_how-to-restore-snapshot-with-full-history.md)
