# test_control_plugin插件

## 描述

`test_control_plugin`插件设计用于在指定区块生产者连续生成区块达到特定区块高度后正常关闭区块链。可指定“头部区块”或“最新不可逆区块”高度为关闭条件。

该插件设计用于测试，确定关闭`qqbcd`实例时刻。

## 使用

```console
# config.ini
plugin = qqbc::test_control_plugin
```

```sh
# command-line
qqbcd ... --plugin qqbc::test_control_plugin
```

## 选项

无

## 依赖关系

* [`chain_plugin`](../chain_plugin/index.md)

### 加载依赖示例

```console
# config.ini
plugin = qqbc::chain_plugin
[options]
```

```sh
# command-line
qqbcd ... --plugin qqbc::chain_plugin [operations] [options]
```
