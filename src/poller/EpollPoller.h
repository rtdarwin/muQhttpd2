#ifndef EPOLL_POLLER_H_
#define EPOLL_POLLER_H_

#include "Poller.h"

class EpollPoller : public Poller
{
public:
    EpollPoller(EventLoop* ownerLoop);
    virtual ~EpollPoller();

    virtual void poll(std::vector<Channel*>* toHandleChannels) override;

    virtual void updateChannel(Channel*) override;
    virtual void removeChannel(Channel*) override;

protected:
    int _epollfd;
};

#endif
