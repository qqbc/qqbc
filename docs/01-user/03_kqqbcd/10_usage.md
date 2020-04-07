# kqqbcd的使用
---

[[提示| 推荐使用 ]]
| 对于大部分用户而言，`kqqbcd`最简便的用法是使用`qqbccli`自动加载。钱包文件默认创建到`~/QQBC-wallet`目录中。

## 手工启动kqqbcd
可使用如下命令，从终端手工启动`kqqbcd`：

```sh
kqqbcd```

默认情况下，`kqqbcd` 将创建文件夹`~/QQBC-wallet`，并生成一个基础的`config.ini`配置文件。可使用命令行参数`--config-dir`指定配置文件位置。配置文件中定义了接收HTTP连接的HTTP服务器端点，以及资源相互交换相关的配置项。

[[提示 | 钱包位置]]
| 钱包数据文件夹位置可使用命令行参数`--data-dir`指定。

## 自锁定

默认情况下，`kqqbcd`会在用户无操作15分钟后自动锁定钱包。具体配置在`config.ini`文件的`unlock-timeout`选项，设置值为超时秒数。如果设置为0，那么`kqqbcd`将维持钱包处于锁定状态。

## 停止kqqbcd
最有效的停止`kqqbcd`进程方法，是确定`kqqbcd`进程号，并发送SIGTERM信号。

## 其它选项

列出`kqqbcd`的全部选项，运行以下命令：

```sh
kqqbcd --help
```

```console
Application Options:

Config Options for qqbc::http_plugin:
  --unix-socket-path arg (=kqqbcd.sock)  The filename (relative to data-dir) to
                                        create a unix socket for HTTP RPC; set
                                        blank to disable.
  --http-server-address arg             The local IP and port to listen for
                                        incoming http connections; leave blank
                                        to disable.
  --https-server-address arg            The local IP and port to listen for
                                        incoming https connections; leave blank
                                        to disable.
  --https-certificate-chain-file arg    Filename with the certificate chain to
                                        present on https connections. PEM
                                        format. Required for https.
  --https-private-key-file arg          Filename with https private key in PEM
                                        format. Required for https
  --https-ecdh-curve arg (=secp384r1)   Configure https ECDH curve to use:
                                        secp384r1 or prime256v1
  --access-control-allow-origin arg     Specify the Access-Control-Allow-Origin
                                        to be returned on each request.
  --access-control-allow-headers arg    Specify the Access-Control-Allow-Header
                                        s to be returned on each request.
  --access-control-max-age arg          Specify the Access-Control-Max-Age to
                                        be returned on each request.
  --access-control-allow-credentials    Specify if Access-Control-Allow-Credent
                                        ials: true should be returned on each
                                        request.
  --max-body-size arg (=1048576)        The maximum body size in bytes allowed
                                        for incoming RPC requests
  --http-max-bytes-in-flight-mb arg (=500)
                                        Maximum size in megabytes http_plugin
                                        should use for processing http
                                        requests. 503 error response when
                                        exceeded.
  --verbose-http-errors                 Append the error log to HTTP responses
  --http-validate-host arg (=1)         If set to false, then any incoming
                                        "Host" header is considered valid
  --http-alias arg                      Additionaly acceptable values for the
                                        "Host" header of incoming HTTP
                                        requests, can be specified multiple
                                        times.  Includes http/s_server_address
                                        by default.
  --http-threads arg (=2)               Number of worker threads in http thread
                                        pool

Config Options for qqbc::wallet_plugin:
  --wallet-dir arg (=".")               The path of the wallet files (absolute
                                        path or relative to application data
                                        dir)
  --unlock-timeout arg (=900)           Timeout for unlocked wallet in seconds
                                        (default 900 (15 minutes)). Wallets
                                        will automatically lock after specified
                                        number of seconds of inactivity.
                                        Activity is defined as any wallet
                                        command e.g. list-wallets.
  --yubihsm-url URL                     Override default URL of
                                        http://localhost:12345 for connecting
                                        to yubihsm-connector
  --yubihsm-authkey key_num             Enables YubiHSM support using given
                                        Authkey

Application Config Options:
  --plugin arg                          Plugin(s) to enable, may be specified
                                        multiple times

Application Command Line Options:
  -h [ --help ]                         Print this help message and exit.
  -v [ --version ]                      Print version information.
  --print-default-config                Print default configuration template
  -d [ --data-dir ] arg                 Directory containing program runtime
                                        data
  --config-dir arg                      Directory containing configuration
                                        files such as config.ini
  -c [ --config ] arg (=config.ini)     Configuration file name relative to
                                        config-dir
  -l [ --logconf ] arg (=logging.json)  Logging configuration file name/path
                                        for library users
```
