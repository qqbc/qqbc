## set account子命令功能

设置或更新区块链账户许可权限。

## 顺位项说明

* `account` _TEXT_：指定设置或删除许可授权的账户名（必需项）。
- `permission` _TEXT_：设置需设置或删除授权的许可名称。
- `authority` _TEXT_：[delete] NULL； [create/update] 公钥、JSON字符串或定义授权的文件名。
- `parent` _TEXT_： [create] 上一级许可的名称（默认：“Active”） (Defaults to: "Active")


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

## 命令

要修改账户的许可，操作者必需具备账户的操作权限和要修改许可的操作权限。set account子命令用于修改相关权限。

第一个例子：将一个新密钥关联到账户现有许可。


```sh
qqbccli set account permission test active '{"threshold" : 1, "keys" : [{"permission":{"key":"QQBC8X7Mp7apQWtL6T2sfSZzBcQNUqZB7tARFEm9gA9Tn9nbMdsvBB","permission":"active"},"weight":1}], "accounts" : [{"permission":{"account":"acc2","permission":"active"},"weight":50}]}' owner
```

第二个例子：通过移除上例设置的密钥，修改上该账户的许可，并授权`@test`账户的现有权限给另一个账户。


```sh
qqbccli set account permission test active '{"threshold" : 1, "keys" : [], "accounts" : [{"permission":{"account":"sandwich","permission":"active"},"weight":1},{"permission":{"account":"acc1","permission":"active"},"weight":50}]}' owner
```

第三个例子：为多签设置许可。

```sh
qqbccli set account permission test active '{"threshold" : 100, "keys" : [{"permission":{"key":"QQBC8X7Mp7apQWtL6T2sfSZzBcQNUqZB7tARFEm9gA9Tn9nbMdsvBB","permission":"active"},"weight":25}], "accounts" : [{"permission":{"account":"@sandwich","permission":"active"},"weight":75}]}' owner
```

上面给出的命令中，使用的JSON对象实际上是由两个不同类型的对象组成：


* 权限对象：

```json
{
  "threshold"       : 100,    /*An integer that defines cumulative signature weight required for authorization*/
  "keys"            : [],     /*An array made up of individual permissions defined with an QQBC PUBLIC KEY*/
  "accounts"        : []      /*An array made up of individual permissions defined with an QQBC ACCOUNT*/
}
```

其中包括一到多个许可对象：

```json
/*Set Permission with Key*/
{
  "permission" : {
    "key"           : "QQBC8X7Mp7apQWtL6T2sfSZzBcQNUqZB7tARFEm9gA9Tn9nbMdsvBB",
    "permission"    : "active"
  },
  weight            : 25      /*Set the weight of a signature from this permission*/
}

/*Set Permission with Account*/
{
  "permission" : {
    "account"       : "sandwich",
    "permission"    : "active"
  },
  weight            : 75      /*Set the weight of a signature from this permission*/
}
```
