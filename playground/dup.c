/**
 * @file 修改fd指向的file结构体
 */
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    int file_fd, stdio_fd;
    char msg[] = "This is a test\n";
    file_fd = open("../playground/.temp/temp.txt", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
    if(file_fd<0) {
        perror("open");
        exit(1);
    }
    // region 保存原stdio，将stdio写为file fd，并关闭file，此时stdio指向的文件结构体变为tty，导致写入stdio变为写入file
    stdio_fd = dup(STDOUT_FILENO);
    dup2(file_fd, STDOUT_FILENO);
    close(file_fd);
    write(STDOUT_FILENO, msg, strlen(msg));
    // endregion
    // region 恢复原stdio，并重新写入
    dup2(stdio_fd, STDOUT_FILENO);
    write(STDOUT_FILENO, msg, strlen(msg));
    close(stdio_fd);
    // endregion
    return 0;
}
