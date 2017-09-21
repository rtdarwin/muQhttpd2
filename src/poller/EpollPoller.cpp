#include "EpollPoller.h"
#include "Channel.h"

#include <poll.h>
#include <sys/epoll.h>
#include <unistd.h>

class EventLoop;

EpollPoller::EpollPoller(EventLoop* ownerLoop)
    : Poller(ownerLoop)
{
    if ((_epollfd = epoll_create1(EPOLL_CLOEXEC)) == -1) {
        // TODO: fatel error
    }
}

EpollPoller::~EpollPoller()
{
    ::close(_epollfd);
}

void
EpollPoller::poll(std::vector<Channel*>* toHandleChannels)
{
}

void
EpollPoller::updateChannel(Channel* c)
{
}

void
EpollPoller::removeChannel(Channel* c)
{
}
