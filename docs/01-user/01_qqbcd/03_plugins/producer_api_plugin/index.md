# producer_api_plugin插件

## 描述

`producer_api_plugin`为[`producer_plugin`](../producer_plugin/index.md)插件提供多个由[`http_plugin`](../http_plugin/index.md)插件管理的RPC API接口。

## 使用

```console
# config.ini
plugin = qqbc::producer_api_plugin
```

```sh
# qqbcd startup params
qqbcd ... --plugin qqbc::producer_api_plugin
```

## 选项

无

## 依赖关系

* [`producer_plugin`](../producer_plugin/index.md)
* [`chain_plugin`](../chain_plugin/index.md)
* [`http_plugin`](../http_plugin/index.md)

### 加载依赖示例

```console
# config.ini
plugin = qqbc::producer_plugin
[options]
plugin = qqbc::chain_plugin
[options]
plugin = qqbc::http_plugin
[options]
```

```sh
# command-line
qqbcd ... --plugin qqbc::producer_plugin [options]  \
           --plugin qqbc::chain_plugin [operations] [options]  \
           --plugin qqbc::http_plugin [options]
```
