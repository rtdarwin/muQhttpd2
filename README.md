# muQhttpd2

[muQhttpd](https://github.com/rtdarwin/muQhttpd) 的 C++ 重实现版。

主要目标：

1. 使用 `one(event) loop per thread + thread pool` 模式提高服务器的最大并发连接数和吞吐量
1. 提高服务器稳定性（完善错误处理）
