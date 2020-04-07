## system newaccount子命令功能

创建账户，购买内存资源，并抵押用于账户的带宽资源。


## 顺位项说明

- `creator` _TEXT_ ：实现新账户创建的账户名称。
- `name` _TEXT_  ：创建的新账户名称。
- `OwnerKey` _TEXT_ ：新账户的所有者公钥。
- `ActiveKey` _TEXT_  ：新账户的在用公钥。

## 选项说明

- `-h,--help`：输出帮助信息并退出。
- `--stake-net` _TEXT_ ：抵押用于网络带宽资源的通证数量。-
- `--stake-cpu` _TEXT_  ：抵押用于CPU带宽资源的通证数量。
- `--buy-ram-bytes` _UINT_：新账户购买内存资源数量（KB）。默认为8KB。
- `--buy-ram-QQBC` _TEXT_ -： 新账户使用QQBC购买的内存资源数量
- `--transfer` ：将投票权和资格转交，以去除抵押的通证，转入接收账户。
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
