## 目标

创建`kqqbcd`钱包。

## 准备工作

* 安装了适用版本的`qqbccli`。

* 理解以下概念：
  * 什么是账户？
  * 什么是密钥对？


## 操作步骤：

创建钱包，并将密码保存到文件中。

```sh
qqbccli wallet create --file password.pwd
```

上面命令输出示例如下。注意：如果没有指定钱包名称，默认为`default`。


```console
Creating wallet: default
Save password to use in the future to unlock this wallet.
Without password imported keys will not be retrievable.
saving password to password.pwd
```

用户也可以使用`-n`选项指定钱包名称。


```sh
qqbccli wallet create -n named_wallet -f passwd
```

输出示例如下：


```console
Creating wallet: named_wallet
Save password to use in the future to unlock this wallet.
Without password imported keys will not be retrievable.
saving password to passwd
```
