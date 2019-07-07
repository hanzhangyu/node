#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

// 运行的bash直接替换了父进程，一般通过 fork 一个子进程然后使用 exec系列函数
// │        └─ bash ../playground/shell/run.sh arg
// │           └─ sleep 10s
int main() {
    char *execv_str[] = {"", "arg", NULL};
    if (execv("../playground/shell/run.sh", execv_str) < 0) {
        perror("error on exec");
        return 0;
    }

    return 0;
}
