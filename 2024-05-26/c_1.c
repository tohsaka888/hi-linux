/**
 * sys/types.h是Unix系统中的一个头文件，它定义了一些数据类型，这些类型在不同的系统上可能会有所不同
 * 这些数据类型在不同的系统上可能会有所不同
 */
#include <sys/types.h>
/**
 * 定义文件状态信息的数据结构
 * 在C语言中，文件状态信息包括文件类型、文件权限、文件大小、文件最后访问时间、文件最后修改时间等。这个头文件提供了许多函数，用于获取和操作文件状态信息。
 */
#include <sys/stat.h>
/**
 * 定义了一些与文件控制相关的函数
 */
#include <fcntl.h>
/**
 * 用来进行文件操作、进程控制、网络通信等
 */
#include <stdio.h>
#include <unistd.h>

void q1(char *src_path, char *dest_path) {
    int fd_src, fd_dest;
    char buff[1024]; /* 1K */
    /* open files */
    fd_src = open(src_path, O_RDONLY);
    fd_dest = open(dest_path, O_RDWR | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH);

    /* seek 500 */
    off_t offset = lseek(fd_src, 500, SEEK_SET);
    if (offset == -1) {
        perror("lseek error!");
    }

    /* read 1K */
    int read_ret = read(fd_src, buff, sizeof(buff));
    if (read_ret == -1) {
        perror("read error!");
    }

    /* write to  */
    int write_ret = write(fd_dest, buff, sizeof(buff));
    if (write_ret == -1) {
        perror("write error!");
    }

    close(fd_src);
    close(fd_dest);
}

int q2(char *path) {
    int fd = open(path, O_RDONLY);
    if (fd) {
        printf("File existed!");
    } else {
        printf("File not exist!\n");
    }
    return fd == -1;
}

int q3(char *path) {
    int fd = open(path, O_WRONLY | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH);
    if (fd == -1) {
        perror("open error!");
        return -1;
    }
    char pre_text[1024];
    char post_text[1024];

    for (int i = 0; i < sizeof(pre_text); i++) {
        pre_text[i] = 0x00;
    }

    for (int i = 0; i < sizeof(post_text); i++) {
        post_text[i] = 0xff;
    }

    int write_ret = write(fd, pre_text, sizeof(pre_text));
    if (write_ret == -1) {
        perror("write error!");
        return -1;
    }

    int seek_ret = lseek(fd, sizeof(pre_text), SEEK_SET);
    if (seek_ret == -1) {
        perror("lseek error!");
        return -1;
    }

    write_ret = write(fd, post_text, sizeof(post_text));
    if (write_ret == -1) {
        perror("write error!");
        return -1;
    }

    close(fd);

    return 0;
}

off_t q4(char *path) {
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("open error!");
        return -1;
    }
    off_t size = lseek(fd, 0, SEEK_END);
    return size;
}

int main(int argc, char const *argv[]) {
    // run q1
    q1("./input.txt", "./output.txt");
    int result = q2("./input.txt");
    printf("result: %d\n", result);
    q3("./q3");
    off_t size = q4("./q3");
    printf("size: %ldBytes\n", size / 1024);
    return 0;
}
