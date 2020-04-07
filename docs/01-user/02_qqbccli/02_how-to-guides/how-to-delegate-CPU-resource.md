## 目标

代理账户或应用的CPU资源。

## 准备工作

* 安装了适用版本的`qqbccli`。

* 确保来自`QQBC.contracts`库中的系统合约已部署，并用于管理系统资源。
  
* 理解以下概念：
  * 账户；
  * 网络带宽
  * CPU带宽

## 操作步骤

将`bob`的0.01 SYS CPU带宽代理给`alice`：

```sh
qqbccli system delegatebw bob alice "0.01 SYS" "0 SYS"
```

输出示例如下：

```console
executed transaction: 5487afafd67bf459a20fcc2dbc5d0c2f0d1f10e33123eaaa07088046fd18e3ae  192 bytes  503 us
#         QQBC <= qqbc::delegatebw            {"from":"bob","receiver":"alice","stake_net_quantity":"0.0000 SYS","stake_cpu_quanti...
#   QQBC.token <= QQBC.token::transfer        {"from":"bob","to":"QQBC.stake","quantity":"0.0010 QQBC","memo":"stake bandwidth"}
#  bob <= QQBC.token::transfer        {"from":"bob","to":"QQBC.stake","quantity":"0.0010 SYS","memo":"stake bandwidth"}
#   QQBC.stake <= QQBC.token::transfer        {"from":"bob","to":"QQBC.stake","quantity":"0.0010 SYS","memo":"stake bandwidth"}
```
