# qqbccli FAQ
---

## 选择Domain Socket (IPC)还是HTTPS (RPC)方式？

区块链提供两种将`qqbccli`连接到`kqqbcd`的方式，即使用socket或HTTPS。socket方式具有多项优点。首先，socket降低了在LAN、WAN甚至是因特网上泄露`kqqbcd`访问情况的风险。其次，不同于HTTPS协议存在CORS等多种攻击方式，socket之用于给定用例情况下的进程内通信（IPC）。


## 提示信息“transaction executed locally, but may not be confirmed by the network yet“是什么意思？

提示表明`qqbccli`提交给`qqbcd`实例的交易已经得到成功接收和执行。`qqbcd`实例会通过P2P网络将交易中继转发给其他的实例，但并不保证其他实例也会成功接收和执行交易。当前也不确保交易会被可信的区块生成者接收和执行，进而加入到区块链上的可信区块中。如果用户希望确保交易添加到不可篡改的区块链上，必需进一步监控交易是否写入区块中。

