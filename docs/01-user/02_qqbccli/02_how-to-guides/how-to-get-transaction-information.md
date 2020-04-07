## 目标

查询交易信息。

## 准备工作

* 安装了适用版本的`qqbccli`。

* 确保来自`QQBC.contracts`库中的系统合约已部署，并用于管理系统资源。
  
* 理解以下概念：
  * 交易。

## 操作步骤

```sh
qqbccli get transaction id
```

[[提示]]
| 应确保所连接的`qqbcd`实例启用了history API插件，支持查询交易信息。
