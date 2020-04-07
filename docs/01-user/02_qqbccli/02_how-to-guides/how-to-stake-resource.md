## 目标

为账户抵押资源。

## 准备工作

* 安装了适用版本的`qqbccli`。

* 确保来自`QQBC.contracts`库中的系统合约已部署，并用于管理系统资源。
  
* 理解以下概念：
  * 账户；
  * 网络带宽
  * CPU带宽

## 操作步骤

为`alice`账户抵押0.01 SYS的网络带宽：

```sh
qqbccli system delegatebw alice alice "0 SYS" "0.01 SYS"
```

为`alice`账户抵押0.01 SYS的CPU带宽：

```sh
qqbccli system delegatebw alice alice "0.01 SYS" "0 SYS"
```