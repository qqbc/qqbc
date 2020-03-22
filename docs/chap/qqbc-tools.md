# 程序与工具

* 程序 
  * Qqbcd
  * qqbccli
  * kqqbcd
  * launcher
  * snapshot
* 工具 
  * eosiocpp

## 程序

### Qqbcd

这部分是运行一个由多个插件配置的节点的 QQBC 核心守护进程，实例的用途主要是生产区块、专用 API 端、和本地部署。

### qqbccli
qqbccli 是一个命令行工具，它与 qqbcd 公开的 REST API 进行交互。 为了使用 qqbccli，您需要将终端（IP 地址和端口号）添加到 qqbcd 实例，并配置 qqbccli 以加载`'eosio :: chain_api_plugin'`。 qqbccli 文件夹中包含所有命令的文档。 有关 qqbccli 已知的所有命令，只需简单地运行它，不需要任何参数：

```
qqbccli
ERROR: RequiredError: Subcommand required
Command Line Interface to QQBC Client
Usage: ./qqbccli [OPTIONS] SUBCOMMAND
Options:
 -h,--help                     打印help内容并退出
 -H,--host TEXT=localhost      其中host 为qqbcd运行的服务器地址信息
 -p,--port UINT=8888           其中port 为qqbcd运行的服务器端口信息
 --wallet-host TEXT=localhost  其中host 为kqqbcd 运行的服务器地址信息
 --wallet-port UINT=8888       其中port 为kqqbcd 运行的服务器端口信息
 -v,--verbose                  输出详细错误信息
Subcommands:
 version                       返回版本号
 create                        创建链上或链下条目
 get                           返回链上对应变量信息
 set                           设置或更改链状态
 transfer                      从一个账户向另一个账户发送EOS
 net                           与P2P网络交互
 wallet                        与本地钱包交互
 benchmark                     配置并执行基准
 push                          向区块链发起交易
```

要获得有关任何特定子命令的帮助，请不要使用参数，并运行它： 

```
qqbccli create
ERROR: RequiredError: Subcommand required
Create various items, on and off the blockchain
Usage: ./qqbccli create SUBCOMMAND
Subcommands:
 key                          创建一个新的公私钥对，并打印出公钥与私钥
 account                      创建一个新的账户
 producer                     创建一个新的区块生产者
qqbccli create account
ERROR: RequiredError: creator
Create a new account on the blockchain
Usage: ./qqbccli create account [OPTIONS] creator name OwnerKey ActiveKey
Positionals:
 creator TEXT                正在创建新账户的账户名称
 name TEXT                   新账户名称
 OwnerKey TEXT               该账户对应的owner公钥
 ActiveKey TEXT              该账户对应的Active公钥
Options:
 -s,--skip-signature         设置不应使用解锁的钱包密钥来签署交易
 -x,--expiration             设置交易最长等待确认时间，以秒为量级, 缺省值为 30s
 -f,--force-unique           强制交易特殊，这将消耗额外带宽，并移除为防止多次意外发布相同交易的任何保护措施
```

### kqqbcd

这是载入由插件配置的钱包的 QQBC 钱包守护进程，如 HTTP 端或 RPC API。 

### launcher

launcher(启动器) 可以使在局域网或广域网中发布多个 eosd 节点更加方便。 可以通过 CLI（命令行）来对 launcher 进行操作，包括用来修改每个节点的配置文件，并且在对等主机之间安全地分发这些配置文件，然后启动 eosd 节点的多个实例。

### snapshot

snapshot 引用了 QQBC/genesis 仓库中相关应用模块，其中包含了用于 crowdsale 合约快照生成的 nodejs 应用程序，用于配置创世区块的 Web 图形界面以及其他与创世相关的工具。
Tools

### eosiocpp

使用 eosiocpp 生成 ABI 规范文件

eosiocpp 可以通过检查合约源码中声明的类型的内容来生成 ABI 规范文件。

为了表明一个类型需要被导出到 ABI（以一个 action 或者一个 table 的形式），@abi注释必须用在类型声明所附的注释中。（annotation comment ？？？？）

注释的语法如下。

```
@abi action [name name2 ... nameN]
@abi table [index_type name]
为了生成 ABI 文件，eosiocpp 被调用的时候必须使用 -g 选项。
➜ eosiocpp -g abi.json types.hpp
Generated abi.json ...
```

eosiocpp 也可用于生成序列化/反序列化 ABI 规范中定义的类型的辅助函数。

```
➜ eosiocpp -g abi.json -gs types.hpp
Generated abi.json ...
Generated types.gen.hpp ...
```

举例

声明一个 action
```
#include <eoslib/types.hpp>
#include <eoslib/string.hpp>

//@abi action
struct action_name {
  uint64_t    param1;
  uint64_t    param2;
  eosio::string param3;
};
{
  "types": [],
  "structs": [{
      "name": "action_name",
      "base": "",
      "fields": {
        "param1": "uint64",
        "param2": "uint64",
        "param3": "string"
      }
    }
  ],
  "actions": [{
      "action_name": "actionname",
      "type": "action_name"
    }
  ],
  "tables": []
}
```

使用同样接口声明多个 action.

```
#include <eoslib/types.hpp>
#include <eoslib/string.hpp>

//@abi action action1 action2
struct action_name {
  uint64_t param1;
  uint64_t param2;
  eosio::string   param3;
};
{
  "types": [],
  "structs": [{
      "name": "action_name",
      "base": "",
      "fields": {
        "param1": "uint64",
        "param2": "uint64",
        "param3": "string"
      }
    }
  ],
  "actions": [{
      "action_name": "action1",
      "type": "action_name"
    },{
      "action_name": "action2",
      "type": "action_name"
    }
  ],
  "tables": []
}
```

声明一个 table

```
#include <eoslib/types.hpp>
#include <eoslib/string.hpp>

//@abi table
struct my_table {
  uint64_t key;
};
{
  "types": [],
  "structs": [{
      "name": "my_table",
      "base": "",
      "fields": {
        "key": "uint64"
      }
    }
  ],
  "actions": [],
  "tables": [{
      "table_name": "mytable",
      "index_type": "i64",
      "key_names": [
        "key"
      ],
      "key_types": [
        "uint64"
      ],
      "type": "my_table"
    }
  ]
}
```

声明一个 table，带有明确的索引类型


a struct 结构体中有 3 个 uint64_t 变量 可以标识成 i64 或者 i64i64i64


```
#include <eoslib/types.hpp>

//@abi table i64
struct my_new_table {
  uint64_t key;
  uint64_t name;
  uint64_t age;
};
{
  "types": [],
  "structs": [{
      "name": "my_new_table",
      "base": "",
      "fields": {
        "key": "uint64",
        "name": "uint64",
        "age": "uint64"
      }
    }
  ],
  "actions": [],
  "tables": [{
      "table_name": "mynewtable",
      "index_type": "i64",
      "key_names": [
        "key"
      ],
      "key_types": [
        "uint64"
      ],
      "type": "my_new_table"
    }
  ]
}
```

使用同样的结构体声明一个 table 和一个 action.

```
#include <eoslib/types.hpp>
#include <eoslib/string.hpp>

/*
 * @abi table
 * @abi action
 */ 
struct my_type {
  eosio::string key;
  eosio::name value;
};
{
  "types": [],
  "structs": [{
      "name": "my_type",
      "base": "",
      "fields": {
        "key": "string",
        "value": "name"
      }
    }
  ],
  "actions": [{
      "action_name": "mytype",
      "type": "my_type"
    }
  ],
  "tables": [{
      "table_name": "mytype",
      "index_type": "str",
      "key_names": [
        "key"
      ],
      "key_types": [
        "string"
      ],
      "type": "my_type"
    }
  ]
}
```

定义导出的例子

```
#include <eoslib/types.hpp>
struct simple {
  uint64_t u64;
};

typedef simple simple_alias;
typedef eosio::name name_alias;

//@abi action
struct action_one : simple_alias {
  uint32_t u32;
  name_alias name;
};
{
  "types": [{
      "new_type_name": "simple_alias",
      "type": "simple"
    },{
      "new_type_name": "name_alias",
      "type": "name"
    }
  ],
  "structs": [{
      "name": "simple",
      "base": "",
      "fields": {
        "u64": "uint64"
      }
    },{
      "name": "action_one",
      "base": "simple_alias",
      "fields": {
        "u32": "uint32",
        "name": "name_alias"
      }
    }
  ],
  "actions": [{
      "action_name": "actionone",
      "type": "action_one"
    }
  ],
  "tables": []
}
```

使用生成的序列化/反序列化函数

```
#include <eoslib/types.hpp>
#include <eoslib/string.hpp>

struct simple {
  uint32_t u32;
  fixed_string16 s16;
};

struct my_complex_type {
  uint64_t u64;
  eosio::string str;
  simple simple;
  bytes bytes;
  public_key pub;
};

typedef my_complex_type complex;

//@abi action
struct test_action {
  uint32_t u32;
  complex cplx;
};
void apply( uint64_t code, uint64_t action ) {
   if( code == N(mycontract) ) {
      if( action == N(testaction) ) {
        auto msg = eosio::current_message<test_action>();
        eosio::print("test_action content\n");
        eosio::dump(msg);

        bytes b = eosio::raw::pack(msg);
        printhex(b.data, b.len);
     }
  }
}
```

NOTE: table 和 action 的名字都不能含有下划线 ("_").

使用测试数据调用合约

```
qqbccli push message mycontract testaction '{"u32":"1000", "cplx":{"u64":"472", "str":"hello", "bytes":"B0CA", "pub":"EOS8CY2pCW5THmzvPTgEh5WLEAxgpVFXaPogPvgvVpVWCYMRdzmwx", "simple":{"u32":"164","s16":"small-string"}}}' -S mycontract
在 qqbcd 控制台将会有如下输出
test_action content
u32:[1000]
cplx:[
  u64:[472]
  str:[hello]
  simple:[
    u32:[164]
    s16:[small-string]
  ]
  bytes:[b0ca]
  pub:[03b41078f445628882fe8c1e629909cbbd67ff4b592b832264dac187ac730177f1]
]
e8030000d8010000000000000568656c6c6fa40000000c736d616c6c2d737472696e6702b0ca03b41078f445628882fe8c1e629909cbbd67ff4b592b832264dac187ac730177f1
```