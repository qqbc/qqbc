# txn_test_gen_plugin插件

## 描述

`txn_test_gen_plugin`用于测试交易。

[[提示]]
更多信息，参阅插件的[README](README.md)文件。

## 使用

```console
# config.ini
plugin = qqbc::txn_test_gen_plugin
[options]
```

```sh
# command-line
qqbcd ... --plugin qqbc::txn_test_gen_plugin [options]
```

## 选项

下列选项可以从`qqbcd`命令行指定，也可以在`config.ini`文件中设置：

```console
Config Options for qqbc::txn_test_gen_plugin:
  --txn-reference-block-lag arg (=0)    Lag in number of blocks from the head 
                                        block when selecting the reference 
                                        block for transactions (-1 means Last 
                                        Irreversible Block)
  --txn-test-gen-threads arg (=2)       Number of worker threads in 
                                        txn_test_gen thread pool
  --txn-test-gen-account-prefix arg (=txn.test.)
                                        Prefix to use for accounts generated 
                                        and used by this plugin
```

## 依赖关系

无
