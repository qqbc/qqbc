# history_api_plugin插件

[[警告| 已禁用功能]]
| `history_api_plugin`插件依赖的`history_plugin`插件已经禁用，并不再维护。请使用[`state_history_plugin`](../state_history_plugin/index.md)插件。

## 描述

`history_api_plugin` 将[`history_plugin`](../history_plugin/index.md)插件功能提供给由[`http_plugin`](../http_plugin/index.md)插件管理的RPC API，为区块链数据提供只读访问。

该插件提供四种RPC API端点：

* get_actions
* get_transaction
* get_key_accounts
* get_controlled_accounts

<!--[[更多信息]]
| See HISTORY section of [RPC API](https://developers.QQBC.io/QQBC-qqbcd/reference).-->

上述四种RPC API分别被如下`qqbccli`命令使用（列出顺序依次对应）：

* get actions
* get transaction
* get accounts
* get servants

## 使用

```console
# config.ini
plugin = qqbc::history_api_plugin
```

```sh
# command-line
qqbcd ... --plugin qqbc::history_api_plugin
```

## 选项

None

## 依赖关系

* [`history_plugin`](../history_plugin/index.md)
* [`chain_plugin`](../chain_plugin/index.md)
* [`http_plugin`](../http_plugin/index.md)

### 加载依赖示例

```console
# config.ini
plugin = qqbc::history_plugin
[options]
plugin = qqbc::chain_plugin
[options]
plugin = qqbc::http_plugin
[options]
```

```sh
# command-line
qqbcd ... --plugin qqbc::history_plugin [options]  \
           --plugin qqbc::chain_plugin [operations] [options]  \
           --plugin qqbc::http_plugin [options]
```
