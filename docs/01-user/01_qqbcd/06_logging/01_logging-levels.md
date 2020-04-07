# 日志记录级别
---

`qqbcd`提供六种日志记录级别：

- all
- debug
- info
- warn
- error
- off  

`logging.json`示例：

```
{
 "includes": [],
 "appenders": [{
     "name": "consoleout", 
     "type": "console",
     "args": {
       "stream": "std_out",
       "level_colors": [{
           "level": "debug",
           "color": "green"
         },{
           "level": "warn",
           "color": "brown"
         },{
           "level": "error",
           "color": "red"
         }
       ]
     },
     "enabled": true
   },{
     "name": "net",
     "type": "gelf",
     "args": {
       "endpoint": "10.10.10.10",
       "host": "test"
     },
     "enabled": true
   }
 ],
 "loggers": [{
     "name": "default",
     "level": "info",
     "enabled": true,
     "additivity": false,
     "appenders": [
       "consoleout",
       "net"
     ]
   },{
     "name": "net_plugin_impl",
     "level": "debug",
     "enabled": true,
     "additivity": false,
     "appenders": [
       "net"
     ]
   }
 ]
}
```
