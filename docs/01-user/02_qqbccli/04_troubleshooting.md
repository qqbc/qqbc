# qqbccli故障排查
---

## Cannot connect to RPC endpoint

检查本地`qqbcd`是否在运行。通过在浏览器中输入如下URL： 

```sh
curl http://localhost:8888/v1/chain/get_info
```

如果尝试访问远端`qqbcd` API端点，使用下面访问路径：


```sh
http://API_ENDPOINT:PORT/v1/chain/get_info
```

将上面命令中的`API_ENDPOINT`和`PORT`替换为远端`qqbcd` API端点的相应配置。

## "Missing Authorizations"

这说明用户并未使用相应的权限。很多情况下，用户在签名交易时使用了错误的账户和许可等级。

