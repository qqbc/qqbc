# qqbcd插件
---

## 概览

插件扩展了`qqbcd`实现的核心功能。其中，一些插件是必需的，例如作为`qqbcd`模块化组成的`chain_plugin`、`net_plugin`和`producer_plugin`。也有一些插件时可选的，这些查询提供并非qqbcd必需功能的额外特性。

各插件详细信息，访问相应插件规格声明：

* [`chain_api_plugin`](chain_api_plugin/index.md)
* [`chain_plugin`](chain_plugin/index.md)
* [`db_size_api_plugin`](db_size_api_plugin/index.md)
* [`faucet_testnet_plugin`](faucet_testnet_plugin/index.md)
* [`history_api_plugin`](history_api_plugin/index.md)
* [`history_plugin`](history_plugin/index.md)
* [`http_client_plugin`](http_client_plugin/index.md)
* [`http_plugin`](http_plugin/index.md)
* [`login_plugin`](login_plugin/index.md)
* [`net_api_plugin`](net_api_plugin/index.md)
* [`net_plugin`](net_plugin/index.md)
* [`producer_plugin`](producer_plugin/index.md)
* [`state_history_plugin`](state_history_plugin/index.md)
* [`test_control_api_plugin`](test_control_api_plugin/index.md)
* [`test_control_plugin`](test_control_plugin/index.md)
* [`txn_test_gen_plugin`](txn_test_gen_plugin/index.md)

[[提示 | qqbcd的模块化实现]]
| 插件用于添加`qqbcd`的功能。`qqbcd`插件并非运行时插件，而是在编译时构建的。
