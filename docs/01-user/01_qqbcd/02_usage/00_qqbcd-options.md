# qqbcd命令行选项
---

`qqbcd`是命令行（CLI）应用。用户可从命令行手工启动`qqbcd`实例，或是编写脚本自动运行。`qqbcd`的操作主要取决于其所加载的插件和使用的插件选项。因此，`qqbcd`应用特性分为两类，即`qqbcd`指定选项和插件指定选项。

## qqbcd指定选项

qqbcd指定选项主要用于用于维护实例运行，例如设置区块链数据存放目录、指定`qqbcd`配置文件名称、设置日志配置文件名称和存储位置等。下面给出运行`qqbcd --help`后的输出，其中列举了qqbcd指定选项。注意：为避免混淆，该命令并不显示插件特定选项。

```console
Application Config Options:
  --plugin arg                          Plugin(s) to enable, may be specified 
                                        multiple times

Application Command Line Options:
  -h [ --help ]                         Print this help message and exit.
  -v [ --version ]                      Print version information.
  --full-version                        Print full version information.
  --print-default-config                Print default configuration template
  -d [ --data-dir ] arg                 Directory containing program runtime 
                                        data
  --config-dir arg                      Directory containing configuration 
                                        files such as config.ini
  -c [ --config ] arg (=config.ini)     Configuration file name relative to 
                                        config-dir
  -l [ --logconf ] arg (=logging.json)  Logging configuration file name/path 
                                        for library users
```

## 插件特定选项

插件特定选项用于控制qqbcd插件的行为。每个插件特定选项名称是唯一的，因此在命令行和`config.ini`配置文件中的出现顺序没有要求。如果用户指定了一个或多个插件特定选择，那么相应的应用插件也必须使用`--plugin`选项指定。否则相应插件特定选项将不起作用。

详细信息，请访问“[插件](../03_plugins/index.md)”一章内容。
