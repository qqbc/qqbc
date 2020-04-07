# 安装QQBC二进制文件
---

## QQBC安装脚本

为便于开发智能合约，用户可使用`qqbc/scripts`文件夹中提供的`qqbc_install.sh`脚本，将构建生成内容可安装到`/usr/local`文件夹中。执行该脚本需要操作系统文件夹的相应权限。操作如下：


```sh
cd ~/qqbc/qqbc
sudo ./scripts/qqbc_install.sh
```

## QQBC手动安装

作为替代`qqbc_install.sh`脚本，用户可以在`qqbc/build`文件夹中调用`make install`命令，完成QQBC二进制文件的安装。同样，执行该命令需要操作系统文件夹的相应权限。操作如下：


```sh
cd ~/qqbc/qqbc/build
sudo make install
```

[下一条]

| [qqbcd](../../../01_qqbcd/index.md)的配置和使用。

| （可选）[测试QQBC二进制文件](04_test-qqbc-binaries.md)。
