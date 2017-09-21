#include "Poller.h"
#include "Channel.h"
#include "poller/EpollPoller.h"
#include "poller/PollPoller.h"

Poller*
Poller::getPoller(EventLoop* loop)
{
    // FIXME: 此处先暂时返回  EpollPoller
    return new EpollPoller(loop);
}

Poller::Poller(EventLoop* ownerLoop)
    : _ownerLoop(ownerLoop)
{
}

bool
Poller::hasChannel(Channel* c)
{
    return _channelsMap.find(c->fd()) != _channelsMap.cend();
}
