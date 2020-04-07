## 目标

添加一个YubiHSM硬件钱包

## 准备工作

* 成功安装当前适用的`kqqbcd`版本；

* 已成功安装YubiHSM2软件包（即YubiHSM2 SDK）；

* 已创建至少具有下列功能之一的AuthKey：

   * sign-ecdsa
   * generate-asymmetric-key
   * export-wrapped

* **删除缺省AuthKey**

[[重要安全警告]]
| 执行下列步骤前，一定要删除缺省AuthKey，并创建新的AuthKey。

## 操作步骤

### 配置`kqqbcd`

   有两种将`kqqbcd`连接到YubiHSM的方式：

   #### 使用YubiHSM connector

   默认情况下，`kqqbcd`将使用默认主机和端口连接到YubiHSM connector。如果使用自定义URL，需在使用选项`--yubihsm-url`或在`config.ini`配置文件中设置`yubihsm-url`指定connector的正确URL。

   #### 通过USB直接连接

   `kqqbcd`支持直接使用USB协议连接到YubiHSM。

   这种情况下，需要设置`kqqbcd`启动选项如下：

   ```sh
   --yubihsm-url=ysb://
   ```

### 使用AuthKey启动`kqqbcd`：

   ```sh
   --yubihsm-authkey Your_AuthKey_Object_Number
   ```

   如果使用YubiHSM connecto，需检查YubiHSM connector是否已经启动。访问YubiHSM URL：
      http://YubiHSM_HOST:YubiHSM_PORT/connector/status。默认主机和端口是http://127.0.0.1:12345。

   输出示例如下：

   ```console
   status=OK
   serial=*
   version=2.0.0
   pid=666
   address=localhost
   port=12345
   ```

### 使用AuthKey密码解锁YubiHSM钱包，选项如下：

   ```sh
   qqbccli wallet unlock -n YubiHSM --password YOUR_AUTHKEY_PASSWORD
   ```

钱包解锁后，就可正常使用`qqbccli wallet`。注意考虑到安全机制，YubiHSM不支持部分wallet子命令，包括检索私钥，移除密钥等。