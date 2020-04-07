# 如何从blocks.log文件重播
---

用户一旦获取重播区块链所需的备份`blocks.log`文件，可将该文件拷贝到本地节点的`data/blocks`目录中，备份所有需要保存的现存内容，并移除`blocks.index`、`forkdb.dat`、`shared_memory.bin`和`shared_memory.meta`。

下表总结了对上述文件需用户执行的操作。

文件夹             | 文件名          | 操作
----------------------- | ------------------ | ------
data/blocks             | blocks.index       | 移除
data/blocks             | blocks.log         | 使用重播`block.log`替换
data/blocks/reversible  | forkdb.dat         | 移除
data/blocks/reversible  | shared_memory.bin  | 移除
data/blocks/reversible  | shared_memory.meta | 移除

指定重播所用的`blocks.log`，可在`config.ini`文件中设置`blocks-dir = "blocks"` ，也可使用`--blocks-dir`命令行选项设置。

```sh
qqbcd --replay-blockchain \
  -e -p QQBC \
  --plugin qqbc::producer_plugin  \
  --plugin qqbc::chain_api_plugin \
  --plugin qqbc::http_plugin      \
  >> qqbcd.log 2>&1 &
```
