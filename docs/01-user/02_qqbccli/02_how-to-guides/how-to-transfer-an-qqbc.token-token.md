## 目标

转账由`QQBC.token`合约生成的通证。


## 准备工作

* 安装了适用版本的`qqbccli`。

* 用户需要转账由`QQBC.token`合约生成的通证，并且用户所连接的区块链网络已经部署了`QQBC.token`合约。

* 理解以下概念：
  * 交易
  * 通证转账交易不可篡改。


## 操作步骤：

假定用户需要从账户`alice`转账`0.0001 SYS`通证到账户`bob`，执行如下命令：

```sh
qqbccli transfer alice bob "0.0001 SYS" "Hodl!" -p alice@active
```
