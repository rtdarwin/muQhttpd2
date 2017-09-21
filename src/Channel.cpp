#include "Channel.h"
#include "EventLoop.h"
#include "poll.h"

Channel::Channel(EventLoop* loop, int fd)
    : _ownerLoop(loop)
    , _fd(fd)
{
}

Channel::~Channel()
{
    removeSelfFromOwnerEvnetLoop();
}

void
Channel::handleEvent()
{
    // FIXME: errorCallback?
    // FIXME: closeCallback?

    if (_receivedEvents & POLLIN) {
        if (_readCallback)
            _readCallback();
    }

    if (_receivedEvents & POLLOUT) {
        if (_writeCallback)
            _writeCallback();
    }
}

int
Channel::fd()
{
    return _fd;
}

void
Channel::enableReading(bool isEnabled)
{
    if (isEnabled) {
        _interestEvents |= POLLIN;
    } else {
        _interestEvents &= ~POLLIN;
    }

    updateSelfToOwnerEventLoop();
}
void
Channel::enableWriting(bool isEnabled)
{
    if (isEnabled) {
        _interestEvents |= POLLOUT;
    } else {
        _interestEvents &= ~POLLOUT;
    }

    updateSelfToOwnerEventLoop();
}

void
Channel::setOnRead(const std::function<void()>& cb)
{
    _readCallback = cb;
}
void
Channel::setOnWrite(const std::function<void()>& cb)
{
    _writeCallback = cb;
}
void
Channel::setOnClose(const std::function<void()>& cb)
{
    _closeCallback = cb;
}
void
Channel::setOnError(const std::function<void()>& cb)
{
    _errorCallback = cb;
}

void
Channel::updateSelfToOwnerEventLoop()
{
    _ownerLoop->updateChannel(this);
}

void
Channel::removeSelfFromOwnerEvnetLoop()
{
    // TODO
}
