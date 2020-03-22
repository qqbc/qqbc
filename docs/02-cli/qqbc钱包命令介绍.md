# 命令行界面钱包

## 综述

命令行界面钱包程序为 kqqbcd,位于 eos/build/programs/kqqbcd 路径下，用于存储交易签名的私钥。kqqbcd 在本地节点上运行，并将私钥保存在本地节点上。

## 如何运行kqqbcd 


默认情况下，kqqbcd会在目录 ~/eosio-wallet 中生成一个基础的配置文件 config.in。在运行命令行钱包时，通过配置命令行参数 --config-dir指定config.ini配置文件的目录。该配置文件中保存用于接入 http 链接的服务器配置http-server-address参数，以及其他用于资源共享的配置参数。

默认情况下，kqqbcd将钱包文件保存在 ~/eosio-wallet 目录下，钱包文件名为：<wallet-name>.wallet。例如，默认钱包文件名为 default.wallet。当建立了其他钱包后，在该目录下会分别建立每个钱包文件，例如当建立了一个名称为"foo"的钱包，会生成一个钱包文件foo.wallet。钱包文件可以通过命令行参数--data-dir存放在指定的目录中。

## 命令参考

与 kqqbcd 交互使用的工具是qqbccli，该命令在目录eos/build/programs/qqbccli 目录下。 该工具提供了与 kqqbcd 交互的各种命令。

* 新建钱包

`qqbccli wallet create ${参数} `

参数说明： -n, --name 文本，钱包名称 如果不提供钱包名称，则会创建一个默认钱包（default.wallet）

* 打开钱包
* 
打开一个已经创建的钱包。在才做一个钱包前需要先打开。

`qqbccli wallet open ${参数} `

参数说明： -n, --name 文本，钱包名称

* 锁定钱包

`qqbccli wallet lock ${参数} `

参数说明： -n, --name 文本，钱包名称 当节点qqbcd被关闭或者钱包服务kqqbcd被关闭，钱包会被锁定。当重启钱包服务后，需要解锁unlock钱包。

* 解锁钱包

`qqbccli wallet unlock ${参数} `

参数说明： -n, --name 文本，钱包名称 --password 钱包密钥，如果不使用此参数，则会提示输入密钥。

* 导入私钥到钱包
  
`qqbccli wallet import ${参数} 私钥 `

参数说明： -n, --name 文本，钱包名称

* 钱包列表

`qqbccli wallet list` 

列出所有钱包，如果钱包名称后出现*号，说明该钱包已经解锁

* 显示私钥

显示所有已经解锁的钱包私钥

`qqbccli wallet keys`

## 使用qqbcd管理钱包

除了使用kqqbcd来管理你的钱包外，还能使用qqbcd来管理钱包。虽然并不推荐使用qqbcd来管理钱包，但是在开发与测试阶段非常有用。 不建议同时使用kqqbcd和qqbcd来管理钱包，虽然不会出现什么问题，但很容易引起混淆。

如果想使用qqbcd来管理钱包的话，在启动qqbcd时，需要添加参数eosio::wallet_api_plugin，或者也可以在配置文件中做相应设置。（wiki 教程中启动qqbcd时，加入了eosio::wallet_api_plugin参数，因此使用 wiki 中的命令启动节点是，无需单独启动kqqbcd）

* 使用方法 1：

`cd build/programs/qqbcd ./qqbcd -e -p eosio --plugin eosio::wallet_api_plugin` 

* 使用方法 2： 在 config.ini 文件中添加：

`plugin = eosio::wallet_api_plugin `

注意：当使用qqbcd来管理钱包时，如果qqbcd关闭，钱包将会被加锁。重新启动qqbcd后，需要使用unlock命令解锁钱包。