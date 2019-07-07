#include <stdio.h>
#include <sys/wait.h> // http://pubs.opengroup.org/onlinepubs/9699919799/functions/wait.html

void printChildStatus(int status) {
    if (WIFEXITED(status))
        printf("child exited with status of %d\n", WEXITSTATUS(status));
    else if (WIFSIGNALED(status)) // kill
        printf("child was terminated by signal %d\n", WTERMSIG(status));
    else if (WIFSTOPPED(status)) // ？
        printf("child was stopped by signal %d\n", WSTOPSIG(status));
    else puts("child exited");
}
