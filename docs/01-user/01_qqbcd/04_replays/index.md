# qqbcd重播
---

qqbcd提供多种重播区块链的方式。重播是非常有用的操作，节点可以通过因特网或是P2P网络下载`blocks.log`文件，并用该文件快速同步区块链最新状态，或是获取区块链上任一时间点的链状态。

数据重播可通过两种方式实现：

- 操作`blocks.log`文件： 
 `blocks.log`文件中包括区块链上所有不可篡改状态。所有`qqbcd`实例将不可篡改区块写入`qqbcd`安装目录下`data/blocks`文件夹中的`blocks.log`文件。使用`blocks.log`文件重播可用于启动`qqbcd`实例，在不增加网络负载的情况下，重建整个区块链历史交易。

- 操作**快照文件**：
可通过运行`qqbcd`实例创建快照文件。区块在创建时，其所引用的区块链状态将添加到快照中。推进使用不可篡改区块生成的快照文件实现重播，这样用户可以快速启动在设定高度具有完整且正确链状态的`qqbcd`实例，而不是要读取当前区块高度处的所有交易历史。这样，`qqbcd`实例可配置运行在设定高度。


## 如何实现重播

* [如何生成区块日志？](how-to-generate-a-blocks.log.md)
* [如何生成快照？](how-to-generate-a-snapshot.md)
* [如何从区块日志重播？](how-to-replay-from-a-blocks.log.md)
* [如何从快照重播？](how-to-replay-from-a-snapshot.md)


## 可用选项

在命令行运行 `qqbcd --help`将给出运行`qqbcd`的所有可用选项。其中与快照和重播相关的选项包括：

 - **--force-all-checks** 
节点运行者可能并不信任`blocks.log`文件的来源，因而想要在运行`qqbcd`前首先使用`--replay-blockchain --force-all-checks`验证区块的正确性。`--force-all-checks`选项标识将传递给`qqbcd`，使其在重播时不跳过任何检查。

 - **--disable-replay-opts**  
重播期间默认`qqbcd`并不创建维护链状态增量更改的堆栈，实现重播性能的优化。该堆栈用于支持可逆区块的状态回滚。设置该选项将关闭重播优化，并创建链状态增量更改的堆栈。用户如何使用了链状态历史相关插件，必需设置该选项。 

 - **--replay-blockchain**  
该选项告知`qqbcd`从位于data/blocks目录的`blocks.log`文件重播。`qqbcd`将清空链上状态，并重播所有区块。 

 - **--hard-replay-blockchain**  
该选项告知`qqbcd`从位于data/blocks目录的`blocks.log`文件重播。`qqbcd`备份当前的`blocks.log`文件，清空链上状态，并重播所有区块。该操作假定备份`blocks.log`文件中可能包含损坏区块，因此`qqbcd`尽可能重播其中所有可用区块。一旦`qqbcd`在从`qqbcd.log`文件重播中发现损坏区块，将通过p2p网络同步链上剩余区块。

 - **--delete-all-blocks**  
该选项告知`qqbcd`清空当前链上状态和本地`blocks.log`文件。如果用户想要进而从p2p网络同步整个区块链，那么需要给出正确的`genesis.json`创世文件。注意，不建议使用该选项。

 - **--truncate-at-block**  
只有在设置值非零时，使用缺省参数`=0`。该选项用于强制区块链重播在设定高度处停止。该选项仅在设置了`--hard-replay-blockchain`选项时生效，或是并非重播而是设置了`--fix-reversible-blocks`选项时。本地`qqbcd`进程将包含设定高度区块处的链状态。该选项对于检查特定高度处区块链状态非常有用，所以主要用于测试和验证，而非用于创建可与整个网络同步的本地`qqbcd`实例。
  
 
 - **--snapshot**  
使用该选项指定重新链上状态所使用的快照文件。该选项并无需重播`blocks.log`文件，而`qqbcd`实例也无需获取整个区块链的历史交易。

 - **--snapshots-dir**  
该选项用于指定快照文件所在目录，绝对路径和相对路径皆可。

 - **--blocks-dir**  
该选项用于指定`blocks.log`文件所在目录，绝对路径和相对路径皆可。
