# test_control_api_plugin插件

## 描述

`test_control_api_plugin`插件向[test_control_plugin](../test_control_plugin/index.md)插件发送控制消息，告知该插件在到达指定区块高度后关闭`qqbcd`实例。该插件主要用于测试。

## 使用

```console
# config.ini
plugin = qqbc::test_control_api_plugin
```

```sh
# command-line
qqbcd ... --plugin qqbc::test_control_api_plugin
```

## 选项

无

## 使用示例

```sh
curl %s/v1/test_control/kill_node_on_producer -d '{ \"producer\":\"%s\", \"where_in_sequence\":%d, \"based_on_lib\":\"%s\" }' -X POST -H \"Content-Type: application/json\"" %
```

## 依赖关系

* [`test_control_plugin`](../test_control_plugin/index.md)
* [`chain_plugin`](../chain_plugin/index.md)
* [`http_plugin`](../http_plugin/index.md)

### 加载依赖示例

```console
# config.ini
plugin = qqbc::chain_plugin
[options]
plugin = qqbc::http_plugin
[options]
```

```sh
# command-line
qqbcd ... --plugin qqbc::chain_plugin [operations] [options]  \
           --plugin qqbc::http_plugin [options]
```
