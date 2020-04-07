# trace_api_plugin插件

## 描述

`trace_api_plugin`插件为用户提供了从指定区块获取已完成动作和相关元数据的稳定可用API。插件新定义了可访问的HTTP端点。（具体细节参见“[API参考](api-reference/index.md)”一节)。

## 使用

```console
# config.ini
plugin = qqbc::trace_api_plugin
[options]
```

```sh
# command-line
qqbcd ... --plugin qqbc::trace_api_plugin [options]
```

## 选项

下列选项可以从`qqbcd`命令行指定，也可以在`config.ini`文件中设置：

```console
Config Options for qqbc::trace_api_plugin:

  --trace-dir (="traces")               the location of the trace directory
                                        (absolute path or relative to
                                        application data dir)
  --trace-slice-stride (=10000)         the number of blocks each "slice" of
                                        trace data will contain on the
                                        filesystem
  --trace-minimum-irreversible-history-blocks (=-1)
                                        Number of blocks to ensure are kept
                                        past LIB for retrieval before "slice"
                                        files can be automatically removed.
                                        A value of -1 indicates that automatic
                                        removal of "slice" files will be
                                        turned off.
  --trace-rpc-abi                       ABIs used when decoding trace RPC
                                        responses.
                                        There must be at least one ABI
                                        specified OR the flag trace-no-abis
                                        must be used.
                                        ABIs are specified as "Key=Value" pairs
                                        in the form <account-name>=<abi-def>
                                        Where <abi-def> can be:
                                           an absolute path to a file
                                        containing a valid JSON-encoded ABI
                                           a relative path from `data-dir` to a
                                        file containing valid JSON-encoded ABI.
  --trace-no-abis                       Use to indicate that the RPC responses
                                        will not use ABIs.
                                        Failure to specify this option when
                                        there are no trace-rpc-abi
                                        configurations will result in an Error.
                                        This option is mutually exclusive with
                                        trace-rpc-api
```

## 依赖关系

* [`chain_plugin`](../chain_plugin/index.md)
* [`http_plugin`](../http_plugin/index.md)

### 加载依赖示例

如果命令行或`config.ini`没有指定选项，那么将默认加载下列插件：

```console
# config.ini
plugin = qqbc::chain_plugin
[options]
plugin = qqbc::http_plugin 
[options]
```

```sh
# command-line
qqbcd ... --plugin qqbc::chain_plugin [options]  \
           --plugin qqbc::http_plugin [options]
```

## 目的

用户在将应用（例如区块浏览器和交易所）集成到QQBC区块链时，可能会需要区块链处理的动作的完整记录，包括从执行智能合约和预定交易中产生的动作。 `trace_api_plugin`意在实现上述功能，目的包括：

* 已完成动作的记录和相关元数据；
* 以消费者为中心的稳定可用API，实现区块检索；
* 在节点实现可维护的资源提交。

由此，`trace_api_plugin`的关键目标之一就是更好地维护节点资源，包括文件系统，磁盘，内存等。该目标不同于已有的`history_plugin`插件，用于提供更多可配置的过滤和查询功能，也不同于已有的`state_history_plugin`插件，用于提供二进制流接口以访问结构链数据、操作数据以及状态增量。

## 示例

Below it is a `qqbcd` configuration example for the `trace_api_plugin` when tracing some QQBC reference contracts:

```sh
qqbcd --data-dir data_dir --config-dir config_dir --trace-dir traces_dir
--plugin qqbc::trace_api_plugin 
--trace-rpc-abi=QQBC=abis/QQBC.abi 
--trace-rpc-abi=QQBC.token=abis/QQBC.token.abi 
--trace-rpc-abi=QQBC.msig=abis/QQBC.msig.abi 
--trace-rpc-abi=QQBC.wrap=abis/QQBC.wrap.abi
```

## 维护指南

为减低`trace_api_plugin`插件占用的磁盘空间，可做如下配置：

```console
  --trace-minimum-irreversible-history-blocks N (=-1) 
```

只要该值不设置为`-1`，那么将在磁盘上保留当前LIB区块的前`N`个区块。

如果不能通过`trace-minimum-irreversible-history-blocks`选项有效管理资源，那么需要建立持续维护机制。在这种情况下，推荐借助于外部系统或进程去实现资源管理。


### 手动文件系统管理

`trace-dir`配置选项定义了`trace_api_plugin`插件创建的所有构件在文件系统上的存储位置。一旦LIB区块经处理生成，那么这些文件就保持不变，并且可以在任何时刻进行清理以腾出文件系统存储空间。目前，文件的存储格式尚待约定，但是其它系统组件可使用任何进程外管理系统删除该目录中的某些或所有文件，无论文件所管理的数据内容，或是否有正在运行的`qqbcd`实例正在访问或者没有访问这些文件。系统认为可用的数据，但是由于手动维护而不再可用时，将导致相应的API端点给出HTTP 404响应。

管理者可与`trace-minimum-irreversible-history-blocks=-1`选项设置一并使用，完全管控`trace-api-plugin`插件生成数据及相关联文件系统资源的全生命周期。

