#include <stdio.h>
#include <sys/wait.h> // http://pubs.opengroup.org/onlinepubs/9699919799/functions/wait.html

//  以下均为子进程
//  ├─ /mnt/f/code/js/node/cmake-build-debug-wsl/popen
//  │  └─ sh -c ../playground/shell/run.sh
//  │     └─ bash ../playground/shell/run.sh
//  │        └─ sleep 10s
int main() {
    char buffer[180];
    FILE *fp = popen("../playground/shell/run.sh", "r"); // 产生子进程，然后从子进程中调用/bin/sh -c 来执行参数command 的指令，并建立IPC管道
    if(fp == NULL)
    {
        printf("error in popen");
        return 1;
    }
    while (fgets(buffer, 100, fp) != NULL)  // 不能提前退出，不然会触发 exitCode 141
    {
        printf("%s", buffer);
    }
    int exit = pclose(fp);
    if(WIFEXITED(exit)) { // 非零打印
        printf("exit status:%d\n", WEXITSTATUS(exit));
    }
}
