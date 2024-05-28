// 创建一个具有空洞的文件。
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char buf1[] = "hello, world";
char buf2[] = "goodbye, world";

int main() {
    // 文件描述符
    int fd = open("file.hole", O_RDWR | O_CREAT,
                  S_IRWXU | S_IRWXG | S_IRWXO);

    if (fd < 0) {
        printf("create file failed\n");
        return -1;
    }

    int write_result = write(fd, buf1, sizeof(buf1));
    if (write_result != sizeof(buf1)) {
        printf("write failed\n");
        return -1;
    }

    off_t offset = lseek(fd, 16384, SEEK_SET);
    if (offset == -1) {
        printf("lseek failed\n");
        return -1;
    }

    // 在空洞后写入
    write_result = write(fd, buf2, sizeof(buf2));
    if (write_result != sizeof(buf2)) {
        printf("write failed\n");
        return -1;
    }

    return 0;
}