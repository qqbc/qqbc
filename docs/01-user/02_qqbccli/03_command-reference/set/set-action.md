## set action子命令功能

设置或更新区块链操作状态。

**命令**

```sh
qqbccli set action
```

**输出**

```console
Usage: qqbccli set action [OPTIONS] SUBCOMMAND

Options:
  -h,--help                   Print this help message and exit

Subcommands:
  permission                  set parmaters dealing with account permissions
```

**命令**

```sh
qqbccli set action permission
```

## 顺位项说明

- `account` TEXT：指定设置/删除许可权限的账户名（必需项）。
- `code` _Text_：操作代码的属主账户名。
- `type` _Type_：操作类型 。
- `requirement` _Type_：执行指定操作所需的许可名称。


## 选项说明

- `-h,--help`：输出帮助信息并退出。
- `--add-code` [code]：将`QQBC.code`许可添加到指定许可权限中。
- `--remove-code` [code]：从指定许可权限中移除`QQBC.code`许可。
- `-x,--expiration` _TEXT_：设定交易过期的时间限（秒数）。默认为30秒。
- `-f,--force-unique`：强制交易唯一。设置将耗费额外带宽，并去除所有防止多次意外发出同一交易的保护措施。
- `-s,--skip-sign`：指定交易签名是否可以使用解锁的钱包密钥。
- `-j,--json`：以JSON格式输出结果。
- `-d,--dont-broadcast`：禁止将交易广播到网络中（只是输出到stdout）。
- `--return-packed`：与`--dont-broadcast`选项一并使用，获取打包的交易。
- `-r,--ref-block` _TEXT_ ：设置用于TAPOS的参考区块号（或区块ID）。
- `-p,--permission`  _TEXT_：指定认证的账户和权限，格式为“account@permission”（默认值为“account@active”）。
- `--max-cpu-usage-ms` _UINT_：设置用于执行交易的CPU使用配额上限（微秒数）。默认为0，表示不设置任何限额。
- `--max-net-usage` _UINT_ ：-设置用于执行交易的网络使用配额上限（字节数。默认为0，表示不设置任何限额。
- `--delay-sec` _UINT_：设置延迟时间。默认为0。


## 使用

```sh
#Link a `voteproducer` action to the 'voting' permissions
qqbccli set action permission sandwichfarm QQBC.system voteproducer voting -p sandwichfarm@voting

#Now can execute the transaction with the previously set permissions. 
qqbccli system voteproducer approve sandwichfarm someproducer -p sandwichfarm@voting
```
