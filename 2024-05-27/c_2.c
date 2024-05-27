
#include <stdio.h>

int main() {
    int c;
    // 从输入流中不停读字符
    // 如果读取字符不为空
    while ((c = getc(stdin)) != EOF) {
        // put字符到输出流中
        if (putc(c, stdout) == EOF) {
            perror("put to stdout error!");
        }
    }
    // 这个C语言函数ferror(stdin)是用来检查标准输入流stdin是否发生错误。如果stdin发生错误，该函数返回一个非零值；否则返回零
    // 在程序中，通常使用ferror(stdin)来检查输入是否正常，例如在循环中读取数据时。如果ferror(stdin)返回非零值，说明输入流已断，需要采取相应的措施，比如等待用户重新输入或退出程序。
    // 也许也可以判断c是否为EOF？
    if (ferror(stdin)) {
        perror("get from stdin error!");
    }
    return 0;
}