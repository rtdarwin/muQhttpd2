#ifndef MUTEX_LOCK_H_
#define MUTEX_LOCK_H_

#include <boost/noncopyable.hpp>
#include <pthread.h>

class MutexLock : boost::noncopyable
{
public:
    MutexLock() { pthread_mutex_init(&_mtx, NULL); }
    void lock() { pthread_mutex_lock(&_mtx); }
    void unlock() { pthread_mutex_unlock(&_mtx); }

private:
    pthread_mutex_t _mtx;
};

class MutexLockGuard : boost::noncopyable
{
public:
    MutexLockGuard(MutexLock& mtx)
        : _mtx(mtx)
    {
        _mtx.lock();
    }

    ~MutexLockGuard() { _mtx.unlock(); }

private:
    MutexLock& _mtx;
};

#endif
