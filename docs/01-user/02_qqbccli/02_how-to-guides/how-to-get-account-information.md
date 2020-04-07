## 目标

查询账户信息。

## 准备工作

* 安装了适用版本的`qqbccli`。
  
* 理解以下概念：
  * 账户。

## 操作步骤

执行如下命令：

```sh
qqbccli get account ACCOUNT_NAME
```

输出示例如下：

```console
created: 2018-06-01T12:00:00.000
privileged: true
permissions:
     owner     1:    1 QQBC6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV
        active     1:    1 QQBC6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV
memory:
     quota:       unlimited  used:     3.004 KiB

net bandwidth:
     used:               unlimited
     available:          unlimited
     limit:              unlimited

cpu bandwidth:
     used:               unlimited
     available:          unlimited
     limit:              unlimited
```

[[提示 | 账户域]]
| 取决于所连接的不同区块链网络，用户看到的账户关联域值存在差异。这取决于在区块链网络上部署的系统合约类型。
