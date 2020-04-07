# 构建QQBC二进制文件
---

## 基本概念：Shell脚本

> QQBC代码库在中`qqbc/scripts`g文件夹中g提供了多个自动化Shell脚本文件，实现QQBC软件的依赖性构建、安装和可选卸载功能。

## 构建脚本

构建脚本首先安装所有依赖文件，然后开始构建QQBC。

脚本支持多种操作系统（[受支持的操作系统列表](../../index.md#supported-operating-systems)）。运行构建脚本，首先手工进入`~/qqbc/qqbc`文件夹中，然后运行相应脚本文件。操作为：

```sh
cd ~/qqbc/qqbc
./scripts/qqbc_build.sh
```

构建脚本产生的中间过程输出在`qqbc/build`文件夹中。构建成功完成后，生成的二进制程序位于`qqbc/build/programs`目录。

[下一条]

| [安装QQBC](03_install-qqbc-binaries.md)。为营造对本地开发更友好的环境，在完成从源代码构建后，强烈推荐执行安装过程。
