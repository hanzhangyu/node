#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./helper.c"

// system 不支持process I/0
// ├─ /mnt/f/code/js/node/cmake-build-debug-wsl/system
// │  └─ sh -c ../playground/shell/run.sh
// │     └─ bash ../playground/shell/run.sh
// │        └─ sleep 10s
//
// 内部实现：使用fork 创建子进程，然后使用execl 运行。并调用wait 等待
// 缺点
int main() {
    puts("start");
    int status = system("../playground/shell/run.sh"); // 出错时只能获取到错误码，无法得到 child_process.stdout
    printChildStatus(status);
    puts("end");
    return (0);
}
