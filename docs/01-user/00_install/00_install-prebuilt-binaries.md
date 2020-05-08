# 安装预先构建二进制文件
## 预先构建二进制文件

预先构建二进制文件适用于如下操作系统。用户可根据自己操作系统选取对应的操作。

### Ubuntu Linux:

#### Ubuntu 18.04软件包安装

```sh
wget https://github.com/qqbc/qqbc/releases/download/v2.0.1-rc1/qqbc_2.0.1-ubuntu-18.04_amd64.deb
sudo apt install ./qqbc_2.0.1-ubuntu-18.04_amd64.deb
```

#### Ubuntu软件包卸载

```sh
sudo apt remove qqbc
```

### 基于RPM的操作系统（包括CentOS、Amazon Linux等）：

#### RPM软件包安装

```sh
wget https://github.com/qqbc/qqbc/releases/download/v2.0.1-rc1/qqbc-2.0.1-1.x86_64.rpm
sudo yum install ./qqbc-2.0.1-1.x86_64.rpm
```

#### RPM软件包卸载

```sh
sudo yum remove qqbc
```

## EOSIO二进制安装位置

完成预先构建二进制安装后，实际二进制文件位于：

* `/usr/local/opt/qqbc/<version-string>/bin`目录（Linux）；

其中，`version-string`表示安装的QQBC版本。

此外，`qqbcd`, `qqbccli`, `kqqbcd`等QQBC程序，将会在`usr/bin`或`usr/local/bin`系统目录中建立软链接，支持在任意目录中直接执行。


