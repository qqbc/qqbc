## Description
Retrieve accounts which are servants of a given account 

## Info

**Command**

```sh
qqbccli get servants
```
**Output**

```console
Usage: qqbccli get servants account

Positionals:
  account TEXT                The name of the controlling account
```

## Command

```sh
qqbccli get servants inita
```

## Output

```json
{
  "controlled_accounts": [
    "tester"
  ]
}
```
