cmake_minimum_required (VERSION 3.0)
project (muQhttpd2 CXX)

# ========================================
# CMake build system

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# ========================================
# compiler flags

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")

set(CMAKE_CXX_FLAGS
  "-std=c++11 \
   -D_XOPEN_SOURCE=600 \
   -ggdb \
   -Wall \
   -Wextra \
   -pthread"
  )

include_directories("./src")

# ========================================
# binary targets

set(MUQHTTPD2_SRCS
  ./src/poller/PollPoller.cpp
  ./src/poller/EpollPoller.cpp

  ./src/Acceptor.cpp
  ./src/AsyncLogger.cpp
  ./src/BlockingQueue.cpp
  ./src/Buffer.cpp
  ./src/Channel.cpp
  ./src/EventLoop.cpp
  ./src/Poller.cpp
  ./src/TcpConnection.cpp
  ./src/ThreadPool.cpp
  ./src/main.cpp
  ./src/muQhttpd2.cpp
  )

add_executable(muQhttpd2 ${MUQHTTPD2_SRCS})

