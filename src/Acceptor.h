#ifndef ACCEPTOR_H_
#define ACCEPTOR_H_

#include <functional>
#include <memory>
#include <sys/socket.h>

class Channel;
class EventLoop;

class Acceptor
{
public:
    Acceptor(EventLoop* loop, const sockaddr* addr, socklen_t len);
    ~Acceptor();

    void setAfterAccept(const std::function<void(int)>& cb);

private:
    void accept();

private:
    std::function<void(int)> _afterAccept;
    int _listenfd;
    Channel* _listenChannel; // owned by this Acceptor
};

#endif
