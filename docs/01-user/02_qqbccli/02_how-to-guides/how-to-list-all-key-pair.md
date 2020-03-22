## Goal

List all key pairs

## Before you begin

* Install the currently supported version of `qqbccli`

* Understand the following:
  * What is a public and private key pair

## Steps

Unlock your wallet

```sh
qqbccli wallet unlock
```

List all public keys:

```sh
qqbccli wallet keys
```

List all private keys:

```sh
qqbccli wallet private_keys

```

[[warning]]
| Be careful never real your private keys in a production enviroment
