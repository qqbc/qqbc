## account子命令功能

从区块链获取账户信息。

## 顺位项说明

- `name` _TEXT_：需检索的账户名。
- `core-symbol` _TEXT_ ：查询区块链的核心标识名。

## 选项说明

- `-j,--json`：以JSON格式输出。

## 示例

### 以格式化数据获取用户**QQBC**的信息

```sh
qqbccli get account QQBC
```
```console
privileged: true
permissions: 
     owner     1:    1 QQBC6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV
        active     1:    1 QQBC6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV
memory: 
     quota:        -1 bytes  used:      1.22 Mb   

net bandwidth: (averaged over 3 days)
     used:                -1 bytes
     available:           -1 bytes
     limit:               -1 bytes

cpu bandwidth: (averaged over 3 days)
     used:                -1 us
     available:           -1 us   
     limit:               -1 us   

producers:     <not voted>
```
### 以JSON格式获取用户**QQBC**的信息


```sh
qqbccli get account QQBC --json
```
```json
{
  "account_name": "QQBC",
  "privileged": true,
  "last_code_update": "2018-05-23T18:00:25.500",
  "created": "2018-03-02T12:00:00.000",
  "ram_quota": -1,
  "net_weight": -1,
  "cpu_weight": -1,
  "net_limit": {
    "used": -1,
    "available": -1,
    "max": -1
  },
  "cpu_limit": {
    "used": -1,
    "available": -1,
    "max": -1
  },
  "ram_usage": 1279625,
  "permissions": [{
      "perm_name": "active",
      "parent": "owner",
      "required_auth": {
        "threshold": 1,
        "keys": [{
            "key": "QQBC6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV",
            "weight": 1
          }
        ],
        "accounts": [],
        "waits": []
      }
    },{
      "perm_name": "owner",
      "parent": "",
      "required_auth": {
        "threshold": 1,
        "keys": [{
            "key": "QQBC6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV",
            "weight": 1
          }
        ],
        "accounts": [],
        "waits": []
      }
    }
  ],
  "total_resources": null,
  "delegated_bandwidth": null,
  "voter_info": {
    "owner": "QQBC",
    "proxy": "",
    "producers": [],
    "staked": 0,
    "last_vote_weight": "0.00000000000000000",
    "proxied_vote_weight": "0.00000000000000000",
    "is_proxy": 0,
    "deferred_trx_id": 0,
    "last_unstake_time": "1970-01-01T00:00:00",
    "unstaking": "0.0000 SYS"
  }
}
```
