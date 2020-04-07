## wallet unlock子命令功能

解锁一个钱包。


## 顺位项说明

无

## 选项说明

- `-n, --name` _TEXT_：需解锁钱包的名称。

`--password` _TEXT_ ：给出`wallet create`命令返回的密码。

## 使用

解锁钱包，需提供创建钱包时生成的密码。

```sh
qqbccli wallet unlock -n second-wallet --password PW5Ji6JUrLjhKAVn68nmacLxwhvtqUAV18J7iycZppsPKeoGGgBEw
```

## 输出


```console
Unlocked: 'second-wallet'
```
