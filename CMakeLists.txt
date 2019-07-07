cmake_minimum_required(VERSION 3.10)
project(node C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

add_executable(hello playground/hello.c)
add_executable(popen playground/popen.c)
add_executable(fork playground/fork.c)
add_executable(thread playground/thread.c)
