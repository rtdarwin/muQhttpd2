#ifndef POLLER_H_
#define POLLER_H_

#include <map>
#include <vector>

class EventLoop;
class Channel;

class Poller
{
public:
    static Poller* getPoller(EventLoop* ownerLoop);

    Poller(EventLoop* ownerLoop);
    virtual ~Poller() = default;

    virtual void poll(std::vector<Channel*>* toHandleChannels) = 0;

    virtual bool hasChannel(Channel*);
    virtual void updateChannel(Channel*) = 0;
    virtual void removeChannel(Channel*) = 0;

protected:
    std::map<int, Channel*> _channelsMap;

private:
    EventLoop* _ownerLoop;
};

#endif
