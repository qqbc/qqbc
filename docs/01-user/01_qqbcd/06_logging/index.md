# qqbcd日志
---

`qqbcd`的日志功能由`logging.json`文件配置。可以通过`qqbcd`命令行选项[设置`logging.json`](00_setup-logging.json.md)。日志配置配置文件中，可对[appenders](#appenders)行为进行定义，并关联到[loggers](#loggers)和[日志记录级别](01_logging-levels.md)。

<span id="appenders"></span>
## Appender

QQBC内置日志功能库支持两类appender：

- [Console](#console)
- [GELF](#gelf) (即Graylog扩展日志格式，Graylog Extended Log Format)

<span id="console"></span>
### Console 

实现输出日志到屏幕终端。配置选项包括：

- `name` ：自定义logger使用实例的名称；
- `type`：`console`；
- `stream`：`std_out`或`std_err`；
- `level_colors`：将日志记录级别映射为不同颜色；
  - level：参见[日志记录级别](01_logging-levels.md)；
  - color：可选项包括`red`、 `green`、`brown`、`blue`、`magenta`、`cyan`、`white`和`console_default`；
- `enabled`：布尔值，启用/禁用appender。

示例：

```json
{
    "name": "consoleout",
    "type": "console",
    "args": {
    "stream": "std_out",

    "level_colors": [{
        "level": "debug",
        "color": "green"
        },{
        "level": "warn",
        "color": "brown"
        },{
        "level": "error",
        "color": "red"
        }
    ]
    },
    "enabled": true
}
```

<span id="gelf"></span>
### GELF

设置日志信息记录到`Graylog`。`Graylog`是一种用于采集、索引和分析日志信息的完全基础平台。该配置选项包括：

 - `name`：自定义logger使用实例的名称；
 - `type`：`gelf`；
 - `endpoint`：IP地址和端口号
 - `host`：Graylog主机名和标识符。
 - `enabled`：布尔值，启用/禁用appender。

示例：

```json
{
    "name": "net",
    "type": "gelf",
    "args": {
        "endpoint": "104.198.210.18:12202”,
        "host": <YOURNAMEHERE IN QUOTES>
    },
    "enabled": true
}
```

<span id="loggers"></span>
## Loggers

QQBC内建的日志功能库当前支持五类logger：

- `default`：默认logger，总是启用的；
- `net_plugin_impl`：用于net插件的详细日志记录；
- `bnet_plugin`：用于bnet插件的详细日志记录；
- `producer_plugin`：用于producer插件的详细日志记录；
- `transaction_tracing`：测定P2P网络中继节点的详细日志。

其配置选项包括：

 - `name` ：必须匹配上面列出的某一名称；
 - `level` ：参见[日志记录级别](01_logging-levels.md)；
 - `enabled`：布尔值，启用/禁用appender；
 - `additivity`：布尔值，为真或为假；
 - `appenders`：按名字列出appender（名字设置在配置文件中）。

示例：

```json
{
    "name": "net_plugin_impl",
    "level": "debug",
    "enabled": true,
    "additivity": false,
    "appenders": [
        "net"
    ]
}
```

[[提示]]
| `net_plugin_impl`、`bnet_plugin`、`producer_plugin`和`transaction_tracing`默认禁用，需要在`logging.json`配置文件中明确定义。
