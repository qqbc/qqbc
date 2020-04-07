## 目标

购买内存资源。


## 准备工作

* 具有一个账户。

* 确保所使用`QQBC.contracts`库中的合约已部署并用管理系统资源。

* 账户持有足量的通证。

* 安装了适用版本的`qqbccli`。

* 钱包已解锁。

## 操作步骤

使用0.1个SYS通证为账户`alice`购买内存资源：

```sh
qqbccli system buyram alice alice "0.1 SYS" -p alice@active
```