---
content_title: Kqqbcd
---

## Introduction

`kqqbcd` is a key manager service daemon for storing private keys and signing digital messages. It provides a secure key storage medium for keys to be encrypted at rest in the associated wallet file. `kqqbcd` also defines a secure enclave for signing transaction created by `qqbccli` or a third part library.

## Installation

`kqqbcd` is distributed as part of the [QQBC software suite](https://github.com/qqbc/qqbc/blob/master/README.md). To install `kqqbcd` just visit the [QQBC Software Installation](../00_install/index.md) section.

## Operation

When a wallet is unlocked with the corresponding password, `qqbccli` can request `kqqbcd` to sign a transaction with the appropriate private keys. Also, `kqqbcd` provides support for hardware-based wallets such as Secure Encalve and YubiHSM.

[[info | Audience]]
| `kqqbcd` is intended to be used by QQBC developers only.
