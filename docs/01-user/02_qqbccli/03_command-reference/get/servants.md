## servants子命令功能

获取指定账户的控制账户信息。

## 操作
```sh
qqbccli get servants
```

**output**

```console
Usage: qqbccli get servants account

Positionals:
  account TEXT                The name of the controlling account
```

## 命令

```sh
qqbccli get servants inita
```

## 输出

```json
{
  "controlled_accounts": [
    "tester"
  ]
}
```
