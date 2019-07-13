#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

// TODO 遇见一个奇怪的是 zombie 变成了 orphan 使得我不得不重启？
int main(void) {
    pid_t pid;
    pid = fork();
    if (pid < 0) printf("Error!\n");
    else if (pid == 0) {
        // 直接退出
        puts("I'm a child");
        puts("exit child");
        exit(0);
    }
    printf("I'm a father, child pid is: %d\n", pid);
    sleep(3);
    // wait(NULL); // 如果不调用wait，子进程退出之后，其PCB还在内存中，在`ps aux` 表现为（重点关注stat与command后面的<defunct>）：
    // paul      6425  0.0  0.0      0     0 pts/0    Z    20:05   0:00 [zombie] <defunct>
    sleep(100);
    puts("exit parent");
    exit(0);
}
