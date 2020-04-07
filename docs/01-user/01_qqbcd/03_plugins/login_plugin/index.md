# login_plugin插件

## 描述

`login_plugin`为QQBC区块链应用提供认证功能。为满足用户验证需求，`login_plugin` API支持应用验证账户是否可登录。

## 使用

```console
# config.ini
plugin = qqbc::login_plugin
[options]
```

```sh
# command-line
qqbcd ... --plugin qqbc::login_plugin [options]
```

## Options


下列选项可以从`qqbcd`命令行指定，也可以配置在`config.ini`文件中：

```console
Config Options for qqbc::login_plugin:
  --max-login-requests arg (=1000000)   The maximum number of pending login 
                                        requests
  --max-login-timeout arg (=60)         The maximum timeout for pending login 
                                        requests (in seconds)
```

## 依赖关系

* [`chain_plugin`](../chain_plugin/index.md)
* [`http_plugin`](../http_plugin/index.md)

### 加载依赖示例

```console
# config.ini
plugin = qqbc::chain_plugin
[options]
plugin = qqbc::http_plugin 
[options]
```

```sh
# command-line
qqbcd ... --plugin qqbc::chain_plugin [options]  \
           --plugin qqbc::http_plugin [options]
```
