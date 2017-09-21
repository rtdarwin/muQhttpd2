#include "AsyncLogger.h"

#include <fcntl.h>
#include <pthread.h>
#include <sys/stat.h>
#include <unistd.h>

AsyncLogger::AsyncLogger()
{
}

void
AsyncLogger::start()
{
}

AsyncLogger&
AsyncLogger::setLogPath(const char* path)
{
}

AsyncLogger&
AsyncLogger::setLogLevel(AsyncLogger::LogLevel level)
{
}

AsyncLogger::LogLevel
AsyncLogger::getLogLevel()
{
}
