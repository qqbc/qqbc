# 钱包规格说明
---

## 钱包导入格式（WIF，Wallet Import Format）

WIF编码用于EDSA私钥。区块链使用与比特币WIF地址相同的版本、校验和编码模式，与现有软件库兼容[1]。

下面给出一个WIF私钥的示例：

```
5HpHagT65TZzG1PH3CSu63k8DbpvD8s5ip4nEB3kEsreAbuatmU
```

该编码方式的适用于：

* 密钥可复制粘贴（需确保内容完整拷贝）；
* 密钥是文本或其它用户可编辑文件格式；
* 密钥长度缩短。

该编码方式不适用于：

* 手工书写密钥。即便是错了一个大小写，也会导致整个密钥不可用。
* 对其中数据做预先检查的二进制文件或计算机存储。

考虑：

* 如果密钥可以写出或是重新生成，推荐使用BIP39编码。
* 最好使用“Private”或“Private Key”标记WIF密钥。

## 私钥生成WIF

1. 无效的私钥全为0。下面以8进制显示了32位长度密钥：

```
0000000000000000000000000000000000000000000000000000000000000000
```

1. 在前面添加“0x80”字节，表示比特币主链。版本字节编码有助于识别私钥，因此QQBC同样使用了版本字节。但不同于比特币，QQBC通常使用由私钥生成的压缩公钥，因此不会对私钥添加“0x01”前缀字节。

```
800000000000000000000000000000000000000000000000000000000000000000
```

3. 对带版本的密钥执行二进制SHA-256哈希，生成：

```
ce145d282834c009c24410812a60588c1085b63d65a7effc2e0a5e3a2e21b236
```

4. 对生成的SHA-256哈希执行二进制SHA-256哈希，生成：

```
0565fba7ebf8143516e0222d7950c28589a34c3ee144c3876ceb01bfb0e9bb70
```

5. 取第二次生成的SHA-256哈希的前4位字节，作为校验码：

```
0565fba7
```

6. 在第2步生成的带版本密钥中，添加4位校验码：

```
8000000000000000000000000000000000000000000000000000000000000000000565fba7
```

7. 对第6步生成结果进行[Base58](http://npmjs.com/package/bs58)编码，得到：

```
5HpHagT65TZzG1PH3CSu63k8DbpvD8s5ip4nEB3kEsreAbuatmU
```

---

## WIF生成私钥（检查校验）

1. 获取WIF密钥，如下：

```
5HpHagT65TZzG1PH3CSu63k8DbpvD8s5ip4nEB3kEsreAbuatmU
```

1. 对WIF字符串做[Base58](http://npmjs.com/package/bs58)解码，8进制表示为：

```
8000000000000000000000000000000000000000000000000000000000000000000565fba7
```

3. 按位分割解码后WIF字符串为校验码（最后4个字节）和加版本的密钥两部分。

```
800000000000000000000000000000000000000000000000000000000000000000
0565fba7
```

1. 在加版本密钥部分执行二进制SHA-256哈希：

```
ce145d282834c009c24410812a60588c1085b63d65a7effc2e0a5e3a2e21b236
```

5. 对生成的SHA-256哈希再次执行二进制SHA-256哈希：


```
0565fba7ebf8143516e0222d7950c28589a34c3ee144c3876ceb01bfb0e9bb70
```

6. 取生成的SHA-256的前4位字节，作为校验码：

```
0565fba7
```

7. 检查步骤3和步骤6分别得到的校验码是否匹配。

8. 将第3步获得的加版本密钥切分为版本号和私钥两部分：

```
80
0000000000000000000000000000000000000000000000000000000000000000
```

9. 如果版本号为“0x80”，那么操作正确无误。

---

## [Base58check](https://www.npmjs.com/package/base58check)


Base58Check是上述算法的一种JavaScript实现，可用于编码和解码WIF私钥。代码如下：

```sh
base58check = require('base58check')
wif = base58check.encode(privateKey = '00'.repeat(32), version = '80', encoding = 'hex')
assert.equal('5HpHagT65TZzG1PH3CSu63k8DbpvD8s5ip4nEB3kEsreAbuatmU', wif)
let {prefix, data} = base58check.decode(wif)
assert.equal(prefix.toString('hex'), '80')
assert.equal(data.toString('hex'), '00'.repeat(32))
```

---

[1] Bitcoin WIF format - https://en.bitcoin.it/wiki/Wallet_import_format
