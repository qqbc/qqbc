## Goal

Connect to a specific `qqbcd` or `kqqbcd` host to send COMMAND

`qqbccli` and `kqqbcd` can connect to a specific node by using the `--url` or `--wallet-url` optional arguments, respectively, followed by the http address and port number these services are listening to.

[[info | Default address:port]]
| If no optional arguments are used (i.e. `--url` or `--wallet-url`), `qqbccli` attempts to connect to a local `qqbcd` or `kqqbcd` running at localhost `127.0.0.1` and default port `8888`.

## Before you begin

* Install the currently supported version of `qqbccli`

## Steps
### Connecting to Qqbcd

```sh
qqbccli -url http://qqbcd-host:8888 COMMAND
```

### Connecting to Kqqbcd

```sh
qqbccli --wallet-url http://kqqbcd-host:8888 COMMAND
```
