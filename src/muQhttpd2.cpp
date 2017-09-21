#include "muQhttpd2.h"
#include "Acceptor.h"
#include "AsyncLogger.h"
#include "EventLoop.h"

#include <arpa/inet.h>
#include <functional>
#include <netinet/in.h>

muQhttpd2::~muQhttpd2()
{
}

void
muQhttpd2::start(char* confFile)
{
    parseConfigFile(confFile);

    /* 1. 启动 Logger */

    AsyncLogger logger;
    logger.setLogPath("./log").setLogLevel(AsyncLogger::LogLevel::INFO).start();

    /*  2. 配置 EventLoop 和 Acceptor */

    sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    if (_ipv4Addr) {
        inet_pton(AF_INET, _ipv4Addr, &servAddr.sin_addr);
    } else {
        servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    }
    servAddr.sin_port = htons(_ipv4Port);

    EventLoop loop;
    Acceptor acceptor(&loop, (sockaddr*)&servAddr, sizeof(servAddr));
    acceptor.setAfterAccept(
        std::bind(&muQhttpd2::afterAccept, this, std::placeholders::_1));

    /*  3. 让 EventLoop 开始工作 --> poll & handle */

    loop.loop();
}

void
muQhttpd2::parseConfigFile(char* confFile)
{
    // FIXME: 真正的读取配置文件

    _logPath = "./";
    _wwwPath = "./";
    _ipv4Addr = "0.0.0.0";
    _ipv4Port = 80;
}

void
muQhttpd2::afterAccept(int connfd)
{
}
