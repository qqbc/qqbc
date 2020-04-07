## 目标

连接到指定的`qqbcd`或`kqqbcd`主机，发送命令。

`qqbccli`和 `kqqbcd`分别支持使用`--url`或`--wallet-url`选项连接到指定节点。选项参数为服务监听的http地址和端口号。

[[提示 | 缺省地址和端口号]]
| 如果`--url`或`--wallet-url`选项未指定参数，那么`qqbccli`将尝试连接到本地默认端口`127.0.0.1:8888`的`qqbcd`或`kqqbcd`。

#
## 准备工作


* 安装了适用版本的`qqbccli`。

## 操作步骤

### 连接到qqbcd

```sh
qqbccli -url http://qqbcd-host:8888 COMMAND
```

### 连接到kqqbcd
```sh
qqbccli --wallet-url http://kqqbcd-host:8888 COMMAND
```
