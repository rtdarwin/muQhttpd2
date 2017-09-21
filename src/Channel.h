#ifndef CHANNEL_H_
#define CHANNEL_H_

#include <functional>

#include <boost/noncopyable.hpp>

class EventLoop;

/*  Channel
 *   - 行为: Channel 具有自动
 *              - 注册 (构造时)
 *              - 更新 (变更 interestEvents 时)
 *              - 删除 (析构时)
 *           自己到 EventLoop 的功能
 *   - 线程安全性: Channel 只会在其 owner EventLoop 中使用，不用考虑其线程安全性
 */

class Channel : boost::noncopyable
{
public:
    Channel(EventLoop* loop, int fd);
    ~Channel();

    /* For: EventLoop & Poller */

    void handleEvent();
    int fd();

    /* For: 配置 Channel */

    // 默认都为 true
    void enableReading(bool);
    void enableWriting(bool);

    void setOnRead(const std::function<void()>& cb);
    void setOnWrite(const std::function<void()>& cb);
    void setOnClose(const std::function<void()>& cb);
    void setOnError(const std::function<void()>& cb);

private:
    void updateSelfToOwnerEventLoop();
    void removeSelfFromOwnerEvnetLoop();

private:
    EventLoop* _ownerLoop;

    int _fd;
    int _interestEvents;
    int _receivedEvents;

    std::function<void()> _readCallback;
    std::function<void()> _writeCallback;
    std::function<void()> _closeCallback;
    std::function<void()> _errorCallback;
};

#endif
