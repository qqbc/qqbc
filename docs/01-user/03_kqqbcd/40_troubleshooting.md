---
content_title: Kqqbcd Troubleshooting
---

## How to solve the error "Failed to lock access to wallet directory; is another `kqqbcd` running"?

Since `qqbccli` may auto-launch an instance of `kqqbcd`, it is possible to end up with multiple instances of `kqqbcd` running. That can cause unexpected behavior or the error message above.

To fix this issue, you can terminate all running `kqqbcd` instances and restart `kqqbcd`. The following command will find and terminate all instances of `kqqbcd` running on the system:

```sh
pkill kqqbcd
```
