#include <stdio.h>
#include <unistd.h>

#define BUFFSIZE 4096

int main() {
    char buf[BUFFSIZE];
    int n;

    // STDIN_FILENO和STDOUT_FILENO是POSIX标准的一部分
    // FIX：每次循环都要读取标准输入
    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
        // 写入的数据如果小于读取的数据，说明写入失败
        // 在“标准输出”中写入“标准输入”的数据
        if (write(STDIN_FILENO, buf, n) != n) {
            perror("write error");
        }
    }
    // 没读取到输入
    if (n < 0) {
        perror("read error");
    }
    return 0;
}