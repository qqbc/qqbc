## 目标

取消对账户或应用的资源代理。

注意：只有已经代理资源的账户，才能做取消代理。


## 准备工作

* 安装了适用版本的`qqbccli`。

* 确保来自`QQBC.contracts`库中的系统合约已部署，并用于管理系统资源。
  
* 理解以下概念：
  * 账户；
  * 网络带宽
  * CPU带宽

## 操作步骤

取消账户`alice`代理的0.01 SYS CPU带宽资源，返回到账户`bob`：

```sh
qqbccli system undelegatebw bob alice "0 SYS" "0.01 SYS"
```

输出示例如下：

```console
executed transaction: e7e7edb6c5556de933f9d663fea8b4a9cd56ece6ff2cebf056ddd0835efa6606  184 bytes  452 us
#         QQBC <= qqbc::undelegatebw          {"from":"alice","receiver":"bob","unstake_net_quantity":"0.0000 QQBC","unstake_cpu_qu...
warning: transaction executed locally, but may not be confirmed by the network yet         ]
```
