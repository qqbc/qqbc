## status子命令功能

显示现有连接状态

**命令**

```sh
qqbccli net status
```

**输出**

```console
Usage: qqbccli net status host

Positionals:
  host TEXT                   The hostname:port to query status of connection
```

给定一个正确的现有网络配置参数`hostname:port`，上面命令将返回JSON格式响应，示例如下：

```
{
  "peer": "hostname:port",
  "connecting": false/true,
  "syncing": false/true,
  "last_handshake": {
    ...
  }
}
```

其中，`last_handshake`结构详细定义在“[网络对等节点协议](https://developers.QQBC.io/welcome/latest/protocol/network_peer_protocol#421-handshake-message)”文档中。