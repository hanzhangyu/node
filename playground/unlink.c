/**
 * @file 正常删除与nodejs表现一致
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define FILE_PATH "../playground/.temp/temp.txt"

int main() {
    if (fork() == 0) {
        sleep(1);
        int result = unlink(FILE_PATH);
        printf("unlink %d\n", result);
        return 0;
    }
    int fd = open(FILE_PATH, O_CREAT);
    sleep(2);

    char buf[500];
    int size= read(fd, buf, 10);
    write(STDOUT_FILENO, buf, size);

    printf("\n%d", fd);
    close(fd);
}
