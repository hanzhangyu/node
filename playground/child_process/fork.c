#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../helper.c"

int main() {
    pid_t fpid; //fpid表示fork函数返回的值
    char *result = "init";
    // 1. 使用相同代码段
    // 2. 数据段与堆栈段复制一份至子进程
    // 3. 而子进程的fork返回值为0，父进程返回子进程pid
    fpid = fork();
    printf("fpid: %d", fpid);
    if (fpid < 0) {
        printf("error in fork");
        return 1;
    }

    if (fpid == 0) {
        printf("child pid: %d\n", getpid());
        printf("child result addr: %p\n", &result); // 虚拟地址一致
        result = "changed";
        sleep(13);
        printf("result: %s\n", result);
        return 0;
    }

    printf("parent result addr: %p\n", &result);
    printf("parent pid: %d\n", getpid());
    printf("result: %s\n", result);
    int status;
    if ((fpid = wait(&status)) == -1)
        perror("wait() error");
    else {
        printf("ended child process pid: %d\n", (int) fpid);
        printChildStatus(status);
    }
    return 0;
}
