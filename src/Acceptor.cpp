#include "Acceptor.h"
#include "Channel.h"

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <functional>

Acceptor::Acceptor(EventLoop* loop, const sockaddr* addr, socklen_t len)
{
    int ret;

    if ((_listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        // TODO: log
    }

    if ((ret = bind(_listenfd, addr, len)) == -1) {
        // TODO: log
    }

    if ((ret = listen(_listenfd, 1024)) == -1) {
        // TODO: log
    }

    _listenChannel = new Channel(loop, _listenfd);
    _listenChannel->setOnRead(std::bind(&Acceptor::accept, this));
}

Acceptor::~Acceptor()
{
    ::close(_listenfd);
}

void
Acceptor::setAfterAccept(const std::function<void(int)>& func)
{
    _afterAccept = func;
}

void
Acceptor::accept()
{
    int connfd;
    sockaddr_in connSock;
    socklen_t len;

    if ((connfd = ::accept(_listenfd, (sockaddr*)&connSock, &len)) == -1) {
        // TODO: fatel log
    }

    if (_afterAccept) {
        _afterAccept(connfd);
    }
}
