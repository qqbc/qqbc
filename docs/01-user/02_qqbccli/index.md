# qqbccli
---
## 本章索引

* [CLI命令选项](03_command-reference\index.md)
* [操作指南](02_how-to-guides\index.md)
* [故障排除](04_troubleshooting.md)
* [常见问题](05_FAQ.md)


## 引言

`qqbccli`是操作`qqbcd`所提供REST API的命令行工具。开发者可使用`qqbccli`部署QQBC智能合约。

## 安装

`qqbccli`作为[QQBC软件](https://github.com/QQBC/QQBC/README.md)组成部分提供。安装`qqbccli`，请参阅“[QQBC软件安装](../00_install/index.md)”一章。

## 使用qqbccli

使用`qqbccli`，用户需知悉`qqbcd`运行实例的端点信息，即IP地址和端口号。此外，`qqbcd`必须配置运行时加载`qqbc::chain_api_plugin` 插件。该插件支持`qqbcd`响应来自`qqbccli`的RPC请求。

### qqbccli命令

列举`qqbccli`所有选项，运行如下命令：

```sh
qqbccli --help
```

```console
Command Line Interface to QQBC Client
Usage: qqbccli [OPTIONS] SUBCOMMAND

Options:
  -h,--help                   Print this help message and exit
  -u,--url TEXT=http://127.0.0.1:8888/
                              the http/https URL where qqbcd is running
  --wallet-url TEXT=unix:///Users/username/QQBC-wallet/kqqbcd.sock
                              the http/https URL where kqqbcd is running
  -r,--header                 pass specific HTTP header; repeat this option to pass multiple headers
  -n,--no-verify              don't verify peer certificate when using HTTPS
  --no-auto-kqqbcd             don't automatically launch a kqqbcd if one is not currently running
  -v,--verbose                output verbose errors and action console output
  --print-request             print HTTP request to STDERR
  --print-response            print HTTP response to STDERR

Subcommands:
  version                     Retrieve version information
  create                      Create various items, on and off the blockchain
  convert                     Pack and unpack transactions
  get                         Retrieve various items and information from the blockchain
  set                         Set or update blockchain state
  transfer                    Transfer tokens from account to account
  net                         Interact with local p2p network connections
  wallet                      Interact with local wallet
  sign                        Sign a transaction
  push                        Push arbitrary transactions to the blockchain
  multisig                    Multisig contract commands
  wrap                        Wrap contract commands
  system                      Send QQBC.system contract action to the blockchain.
```

### qqbccli子命令

查询任何子命令，运行`qqbccli SUBCOMMAND --help`。例如：

```sh
qqbccli create --help
```

```console
Create various items, on and off the blockchain
Usage: qqbccli create SUBCOMMAND

Subcommands:
  key                         Create a new keypair and print the public and private keys
  account                     Create a new account on the blockchain
                              (assumes system contract does not restrict RAM usage)
```

`qqbccli` can also provide usage help for subcommands within subcommands. For instance:

```sh
qqbccli create account --help
```

```console
Create a new account on the blockchain (assumes system contract does not restrict RAM usage)
Usage: qqbccli create account [OPTIONS] creator name OwnerKey [ActiveKey]

Positionals:
  creator TEXT                The name of the account creating the new account (required)
  name TEXT                   The name of the new account (required)
  OwnerKey TEXT               The owner public key or permission level for the new account (required)
  ActiveKey TEXT              The active public key or permission level for the new account

Options:
  -h,--help                   Print this help message and exit
  -x,--expiration             set the time in seconds before a transaction expires, defaults to 30s
  -f,--force-unique           force the transaction to be unique. this will consume extra bandwidth and remove any protections against accidently issuing the same transaction multiple times
  -s,--skip-sign              Specify if unlocked wallet keys should be used to sign transaction
  -j,--json                   print result as json
  --json-file TEXT            save result in json format into a file
  -d,--dont-broadcast         don't broadcast transaction to the network (just print to stdout)
  --return-packed             used in conjunction with --dont-broadcast to get the packed transaction
  -r,--ref-block TEXT         set the reference block num or block id used for TAPOS (Transaction as Proof-of-Stake)
  --use-old-rpc               use old RPC push_transaction, rather than new RPC send_transaction
  -p,--permission TEXT ...    An account and permission level to authorize, as in 'account@permission' (defaults to 'creator@active')
  --max-cpu-usage-ms UINT     set an upper limit on the milliseconds of cpu usage budget, for the execution of the transaction (defaults to 0 which means no limit)
  --max-net-usage UINT        set an upper limit on the net usage budget, in bytes, for the transaction (defaults to 0 which means no limit)
  --delay-sec UINT            set the delay_sec seconds, defaults to 0s
```

## qqbccli示例

如下`qqbccli`命令创建名称为`mywallet`的本地钱包，并显示密码：

```sh
qqbccli wallet create -n mywallet --to-console
```

```console
Creating wallet: mywallet
Save password to use in the future to unlock this wallet.
Without password imported keys will not be retrievable.
"PW5JbF34UdA193Eps1bjrWVJRaNMt1VKddLn4Dx6SPVTfMDRnMBWN"
```
