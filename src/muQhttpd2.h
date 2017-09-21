#ifndef MUQHTTPD2_H_
#define MUQHTTPD2_H_

#include "sys/types.h"
#include <netinet/in.h>
#include <sys/socket.h>

#include <boost/noncopyable.hpp>
#include <map>
#include <memory>
#include <string>

#include "Acceptor.h"
#include "TcpConnection.h"

class EventLoop;

class muQhttpd2 : boost::noncopyable
{
public:
    muQhttpd2() = default;
    ~muQhttpd2();

    void start(char* confFile);

private:
    void parseConfigFile(char* confFile);
    void afterAccept(int fd);

private:
    /* 配置 */

    char* _logPath = nullptr;
    char* _wwwPath = nullptr;
    char* _ipv4Addr = nullptr;
    uint16_t _ipv4Port = 80;

    /* 持有的 TCP 连接 */

    std::map<std::string, std::shared_ptr<TcpConnection>> _connectionMap;
};

#endif
