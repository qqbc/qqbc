## system voteproducer prods子命令功能

对新的生产者列表进行投票。

## 顺位项说明

- `voter` _TEXT_：投票账户。
- `producers` _TEXT_ ：被投票账户。从此处开始的字符串将被视为生产者列表参数。

## 选项说明

- `-h,--help`：输出帮助信息并退出。
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
