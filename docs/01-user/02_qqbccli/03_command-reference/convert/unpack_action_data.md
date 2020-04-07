## 子命令功能
解包为JSON操作数据

## 顺位项说明
- `account` _TEXT_： 部署合约的账户名；
- `name` _TEXT_：操作调用的功能名称；
- `packed_action_data` _TEXT_：以打包八进制串表示的操作数据。
  
## 选项

- `-h,--help`：打印帮助信息并退出。

## 使用


```sh
 qqbccli convert unpack_action_data QQBC unlinkauth 000000008090b1ca000000000091b1ca000075982aea3055
```

## 输出


```json
{
  "account": "test1",
  "code": "test2",
  "type": "QQBCQQBC"
}
```
