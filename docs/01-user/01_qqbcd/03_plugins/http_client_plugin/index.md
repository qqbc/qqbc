# http_client_plugin插件

## 描述

`http_client_plugin`是一种内部功能插件，为`producer_plugin`插件提供安全使用内部`kqqbcd`实例作为其区块签名者的功能。该插件只能在已配置`producer_plugin`插件生成区块的情况下使用。

## 使用

```console
# config.ini
plugin = qqbc::http_client_plugin
https-client-root-cert = "path/to/my/certificate.pem"
https-client-validate-peers = 1
```

```sh
# command-line
qqbcd ... --plugin qqbc::http_client_plugin  \
           --https-client-root-cert "path/to/my/certificate.pem"  \
           --https-client-validate-peers 1
```

## 选项

下列选项可以从`qqbcd`命令行指定，也可以配置在`config.ini`文件中：

```console
Config Options for qqbc::http_client_plugin:
  --https-client-root-cert arg          PEM encoded trusted root certificate 
                                        (or path to file containing one) used 
                                        to validate any TLS connections made.  
                                        (may specify multiple times)
                                        
  --https-client-validate-peers arg (=1)
                                        true: validate that the peer 
                                        certificates are valid and trusted, 
                                        false: ignore cert errors
```

## 依赖关系

* [`producer_plugin`](../producer_plugin/index.md)
