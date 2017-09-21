#ifndef EVENT_LOOP_H_
#define EVENT_LOOP_H_

#include <cinttypes>
#include <functional>
#include <memory>
#include <vector>

#include <boost/noncopyable.hpp>

#include "MutexLock.h"

class Channel;
class Poller;

/** How EventLoop works
 *
 *        poll ---> handle ---> pendingTasks
 *          ^                            |
 *          |                            |
 *          |----------------------------|
 */

class EventLoop : boost::noncopyable
{
public:
    EventLoop();
    ~EventLoop();

    void loop();
    uint64_t loopTimes();

    void updateChannel(Channel*);
    void removeChannel(Channel*);

    void queueInLoop(const std::function<void()>& task);
    size_t queuedTasksSize() { return _pendingTasks.size(); }

private:
    /* status & flags */
    bool _quit;
    bool _looping;
    MutexLock _loopTimesMtx;
    uint64_t _loopTimes;

    /* poll & handle */
    std::unique_ptr<Poller> _poller;
    std::vector<Channel*> _toHandleChannels;

    /* tasks queue */

    // 多个线程（比如 ThreadPool 中的各计算线程）
    // 都可能会向 EventLoop 放入 task，
    // 需要保证 tasks queue 的线程安全
    MutexLock _tasksMtx;
    std::vector<std::function<void()>> _pendingTasks;
};

#endif
