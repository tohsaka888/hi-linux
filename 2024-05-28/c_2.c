// 测试对其标准输入能否设置偏移量。
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    // 标准输入文件描述符
    // 表示系统默认的输入设备，通常是终端
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        printf("cannot seek");
    else
        printf("seek ok");
    return 0;
}