# wallet_plugin插件

## 功能描述

`wallet_plugin`插件为节点添加了钱包访问功能。

[[注意]]
| 该插件并非设计用于没有任何安全措施而运行在公开可访问网络上的节点，尤其是在加载了不适用在公开可访问网络上使用的`wallet_api_plugin`插件的情况下。

## 使用

```sh
# config.ini
plugin = qqbc::wallet_plugin

# command-line
qqbcd ... --plugin qqbc::wallet_plugin
```

## 选项说明

无

## 依赖关系

* [`wallet_plugin`](../wallet_plugin/index.md)
* [`http_plugin`](../http_plugin/index.md)

### 加载依赖示例

```sh
# config.ini
plugin = qqbc::wallet_plugin
[options]
plugin = qqbc::http_plugin
[options]

# command-line
qqbcd ... --plugin qqbc::wallet_plugin [options]  \
           --plugin qqbc::http_plugin [options]
```
