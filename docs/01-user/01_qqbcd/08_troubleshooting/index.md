# qqbcd常见问题
---

### "Database dirty flag set (likely due to unclean shutdown): replay required"

`qqbcd`需要正确关闭。为确保正常关闭`qqbcd`，需发送`SIGTERM`、`SIGQUIT`或`SIGINT`，然后等待进程关闭。如果关闭失败，将给出上面提示信息。可以使用`--replay-blockchain`选项运行`qqbcd`，通过重播尝试解决问题。

### 在启动时报错“Memory does not match data”

如果在启动`qqbcd`时提示错误`St9exception: content of memory does not match data expected by executable`，尝试使用下面选项重新启动`qqbcd`。详细信息，可使用`qqbcd --help`列出。

```
Command Line Options for qqbc::chain_plugin:
    --fix-reversible-blocks               recovers reversible block database if 
                                          that database is in a bad state
    --force-all-checks                    do not skip any checks that can be 
                                          skipped while replaying irreversible 
                                          blocks
    --replay-blockchain                   clear chain state database and replay 
                                          all blocks
    --hard-replay-blockchain              clear chain state database, recover as 
                                          many blocks as possible from the block 
                                          log, and then replay those blocks
    --delete-all-blocks                   clear chain state database and block 
                                          log
```

### 报错"Could not grow database file to requested size."

使用`--shared-memory-size-mb 1024`选项启动`qqbcd`。1 GB共享内存可支持近50万交易。

### 如何查看搜使用的QQBC版本？

在缺省情况下，可使用`qqbccli get info`生成一个包含`server_version`信息域的区块。如果`qqbcd`并未使用缺省配置，那么需要使用`qqbcd`的URL，命令如下：


```sh
qqbccli --url http://localhost:8888 get info
```

只需关注输出中的`server_version`一行：

```sh
qqbccli --url http://localhost:8888 get info | grep server_version
```

### Error 3070000: WASM Exception Error

启动基于QQBC的区块链时，如果用户在部署`QQBC.bios`合约或`QQBC.system`合约中出现类似如下错误：`Publishing contract... Error 3070000: WASM Exception Error Details: env.set_proposed_producers_ex unresolveable`，这是因为需要首先激活`PREACTIVATE_FEATURE`协议。配置细节及方式，参见“[启动顺序指南](https://developers.QQBC.io/welcome/latest/tutorials/bios-boot-sequence/#112-set-the-QQBCsystem-contract)”，详细信息，可访问“[qqbcd升级指南](https://developers.QQBC.io/manuals/QQBC/latest/qqbcd/upgrade-guides/)”。

