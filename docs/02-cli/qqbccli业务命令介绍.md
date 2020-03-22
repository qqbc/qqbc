## 客户端名称
qqbccli

## 客户端详细帮助
qqbccli --help

## 操作命令
qqbc作为eos fork, 其客户端命令保持了EOS最大兼容。具体详细操作可见:

- [eos客户端操作命令](https://developers.eos.io/manuals/eos/latest/cleos/command-reference/index)
- [qqbccli命令介绍](./qqbccli命令介绍.md)


## QQBC特有命令

#### 邀请用户参与投票

命令格式：
```
qqbccli system invite [OPTIONS] inviter invitees...
```
帮助：
```
qqbccli system invite --help
```
例子：

```
	//user1邀请user2投票
	qqbccli system invite user1 user2
```

#### 检查受邀列表
命令格式：
```
qqbccli system listinviters [OPTIONS] account
```
帮助：
```
qqbccli system listinviters --help
```
例子：
```
	//查看user2的邀请者
	qqbccli system listinviters user2
```