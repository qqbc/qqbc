# net_api_plugin插件

## 描述

 `net_api_plugin`插件将`net_plugin`插件功能暴露给`http_plugin`插件管理的RPC API。

`net_api_plugin`插件提供下列四种RPC API端点：

* connect
* disconnect
* connections
* status

<!--参见“[Net section of RPC API](https://developers.QQBC.io/QQBC-qqbcd/reference).-->

[注意]]
| 该插件暴露的端口支持对p2p连接的管理。不推荐在公网可访问的节点上运行该插件，会导致安全问题。

## 使用

```console
# config.ini
plugin = qqbc::net_api_plugin
```

```sh
# command-line
qqbcd ... --plugin qqbc::net_api_plugin
```

## 选项

无

## 依赖关系

* [`net_plugin`](../net_plugin/index.md)
* [`http_plugin`](../http_plugin/index.md)

### 加载依赖示例

```console
# config.ini
plugin = qqbc::net_plugin
[options]
plugin = qqbc::http_plugin
[options]
```

```sh
# command-line
qqbcd ... --plugin qqbc::net_plugin [options]  \
           --plugin qqbc::http_plugin [options]
```
