#ifndef BASE_ASYNC_LOGGER_H
#define BASE_ASYNC_LOGGER_H

#include <boost/noncopyable.hpp>

class Log;

class AsyncLogger : public boost::noncopyable
{
public:
    enum class LogLevel
    {
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATEL
    };

public:
    AsyncLogger();
    void start();

    AsyncLogger& setLogPath(const char*);
    AsyncLogger& setLogLevel(LogLevel);
    LogLevel getLogLevel();

private:
};

#define ALOG_INFO                                                              \
    {                                                                          \
    }

#endif
