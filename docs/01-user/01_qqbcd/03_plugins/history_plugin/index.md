# history_plugin插件

[[警告 | 已禁用]]
| `history_plugin`插件已禁用，并不再维护。请使用[`state_history_plugin`](../state_history_plugin/index.md)插件。

## 描述

`history_plugin`插件为获取区块链队列历史数据提供了缓存层。该插件对区块链数据的操作依赖于[`chain_plugin`](../chain_plugin/index.md)插件。

## 使用

```console
# config.ini
plugin = qqbc::history_plugin
[options]
```

```sh
# command-line
qqbcd ... --plugin qqbc::history_plugin [options]
```

## 选项

下列选项可以从`qqbcd`命令行指定，也可以配置在`config.ini`文件中：

```console
Config Options for qqbc::history_plugin:
  -f [ --filter-on ] arg                Track actions which match 
                                        receiver:action:actor. Actor may be 
                                        blank to include all. Action and Actor 
                                        both blank allows all from Recieiver. 
                                        Receiver may not be blank.
  -F [ --filter-out ] arg               Do not track actions which match 
                                        receiver:action:actor. Action and Actor
                                        both blank excludes all from Reciever. 
                                        Actor blank excludes all from 
                                        reciever:action. Receiver may not be 
                                        blank.
```

## 依赖关系

* [`chain_plugin`](../chain_plugin/index.md)
