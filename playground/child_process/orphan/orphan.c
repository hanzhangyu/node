/**
 * @file 直接编译之后运行。使用clion运行结果会不一致
 */
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    printf("start parent at: %d\n", getpid());
    pid_t pid;
    pid = fork();
    if (pid < 0) printf("Error!\n");
    else if (pid == 0) {
        printf("start child at: %d\n", getpid());
        sleep(40);
        puts("exit child");
        exit(0);
    }
    sleep(20);
    puts("exit parent");
    exit(0); // 退出之后子进程变为孤儿进程
}
