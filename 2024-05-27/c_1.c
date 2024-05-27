#include <stdio.h>
#include <unistd.h>

#define BUFFSIZE 4096

int main() {
    char buf[BUFFSIZE];

    // STDIN_FILENO和STDOUT_FILENO是POSIX标准的一部分
    int n = read(STDIN_FILENO, buf, BUFFSIZE);
    while (n > 0) {
        if (write(STDIN_FILENO, buf, n) != n) {
            perror("write error");
        }
    }

    if (n < 0) {
        perror("read error");
    }
    return 0;
}