## 子命令功能
将JSON操作数据打包

## 顺位项说明
- `account` _TEXT_ ：部署合约的账户名；
- `name` _TEXT_：操作调用的功能名；
- `unpacked_action_data` _TEXT_ ：JSON表述的操作数据。

## 选项

- `-h,--help`：输出帮助消息并退出。

## 使用
```sh
 qqbccli convert pack_action_data QQBC unlinkauth '{"account":"test1", "code":"test2", "type":"QQBCQQBC"}'
```

## 输出


```console
000000008090b1ca000000000091b1ca000075982aea3055
```
