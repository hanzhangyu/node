cmake_minimum_required(VERSION 3.10)
project(node C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

add_executable(hello playground/hello.c)
add_executable(popen playground/child_process/popen.c)
add_executable(fork playground/child_process/fork.c)
add_executable(thread playground/thread.c)
add_executable(exec playground/child_process/exec.c)
add_executable(system playground/child_process/system.c)
add_executable(zombie playground/child_process/zombie.c)
add_executable(orphan playground/child_process/orphan/orphan.c)
add_executable(helper playground/helper.c)
add_executable(unlink playground/unlink.c)
add_executable(dup playground/dup.c)
