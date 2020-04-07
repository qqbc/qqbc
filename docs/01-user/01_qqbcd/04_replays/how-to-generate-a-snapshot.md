# 如何生成快照
---

用户可使用`create_snapshot` RPC API调用强制`qqbcd`运行实例创建快照。该API由`producer_api_plugin`插件提供，将在`data/snapshots`目录创建快照文件。快照文件在磁盘上以`*snapshot-\<head_block_id_in_hex\>.bin*`文件格式保存。


[[提示] | 快照保存位置]]
| 快照默认写入`qqbcd`数据目录下的`data/snapshots`文件夹中。参见`-d [ --data-dir ]`选项。

对于本地运行的`qqbcd` 实例，下面命令将请求`qqbcd`创建快照：

```sh
curl --request POST \
  --url http://127.0.0.1:8888/v1/producer/create_snapshot \
  --header 'content-type: application/x-www-form-urlencoded; charset=UTF-8'
```

[[提示 | 第三方`blocks.log`文件]]
| 用户可从第三方提供商下载`blocks.log`文件。
