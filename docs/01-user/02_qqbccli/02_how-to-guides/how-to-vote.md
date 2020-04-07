## 目标

对区块生产者投票。

## 准备工作

* 安装了适用版本的`qqbccli`。

* 确保来自`QQBC.contracts`库中的系统合约已部署，并用于管理系统资源。
  
* 理解以下概念：
  * 区块生产者；
  * 投票的工作机制。

* 钱包已经解锁。

## 操作步骤

用户从账户`QQBCtestts2`给`blockproducer1`和`blockproducer2`投票，命令如下：

```sh
qqbccli system voteproducer prods QQBCtestts2 blockproducer1 blockproducer2
```

输出示例如下：

```console
executed transaction: 2d8b58f7387aef52a1746d7a22d304bbbe0304481d7751fc4a50b619df62676d  128 bytes  374 us
#         QQBC <= qqbc::voteproducer          {"voter":"QQBCtestts2","proxy":"","producers":["blockproducer1","blockproducer2"]}
```
