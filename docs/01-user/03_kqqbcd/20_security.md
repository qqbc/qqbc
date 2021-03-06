# kqqbcd的安全性
---

### 解释`kqqbcd`锁定和解锁的工作机制，存在哪些安全隐患。

从用户角度看，钱包一旦创建，就保持`unlocked`状态。根据`kqqbcd`的启动方式，钱包可能会在进程重启前一直保持`unlocked`状态。一旦钱包因为超时或进程重启而锁定，那么需要输入密码才能解锁钱包。

但需要强调的是，`kqqbcd`在存储和检索私钥并对消息数字签名中，除了钱包锁定和解锁操作外，并不提供任何认证或授权机制。


### 如何访问`kqqbcd`服务，存在哪些安全隐患。

如果使用域socket访问`kqqbcd`，所有具有访问和写入文件系统上socket文件的UNIX用户或用户组，都可以使用任何已解锁签名中的密钥提交交易，并从`kqqbcd`接收已签名的交易。

如果TCP socket绑定到本地主机，那么无论所有者或权限如何，任何本地进程都可以执行上述同一操作。其中包括运行在本地浏览器中网页中的一段JavaScript代码，尽管某些浏览器可能对此有一些安全上的考虑。

如果TCP socket绑定到LAN/WAN地址，那么任何可将数据包发送到运行`kqqbcd`主机的远程角色都执行上述同一操作。即使使用了HTTPS对通信进行加密或保护，也存在巨大的安全风险。

