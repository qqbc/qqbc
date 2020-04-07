## Goal


取消账户抵押的网络资源。

注意：只有代理了资源的账户，才能执行取消代理操作。

## 准备工作

* 安装了适用版本的`qqbccli`。

* 确保来自`QQBC.contracts`库中的系统合约已部署，并用于管理系统资源。
  
* 理解以下概念：
  * 账户；
  * 网络带宽
  * CPU带宽

## 操作步骤

为`alice`账户取消0.01 SYS网络带宽的抵押：


```sh
qqbccli system undelegatebw alice alice "0 SYS" "0.01 SYS"
```

输出示例为：

```console
executed transaction: e7e7edb6c5556de933f9d663fea8b4a9cd56ece6ff2cebf056ddd0835efa6606  184 bytes  452 us
#         QQBC <= qqbc::undelegatebw          {"from":"alice","receiver":"alice","unstake_net_quantity":"0.01 QQBC","unstake_cpu_qu...
warning: transaction executed locally, but may not be confirmed by the network yet         ]
```
