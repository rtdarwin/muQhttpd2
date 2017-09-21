#include "EventLoop.h"
#include "Channel.h"
#include "MutexLock.h"
#include "Poller.h"

EventLoop::EventLoop()
    : _poller(Poller::getPoller(this))
{
}

EventLoop::~EventLoop()
{
}

void
EventLoop::loop()
{
    while (!_quit) {
        {
            MutexLockGuard lock(_tasksMtx);
            ++_loopTimes;
        }
    }
}

uint64_t
EventLoop::loopTimes()
{
    MutexLockGuard lock(_loopTimesMtx);
    return _loopTimes;
}

void
EventLoop::updateChannel(Channel* c)
{
}

void
EventLoop::removeChannel(Channel* c)
{
}

void
EventLoop::queueInLoop(const std::function<void()>& task)
{
}
