// 从标准输入读命令并执行
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

/**
fork之后当前线程（父线程）和子线程都会执行，通过pid判断是在父进程执行的还是子进程执行的，如果pid为0说明是在子进程执行的，pid>0说明是父进程执行的（pid）是子进程的id。

一般需要独立执行的时候使用进程，需要共享数据时使用线程。
*/

int main() {
    char cmd[MAX_CMD_LEN];
    pid_t pid;
    int status;

    // 需要%%才能正确显示%
    printf("%% ");

    // 从stdin中读取命令（回车终止）
    while (fgets(cmd, sizeof(cmd), stdin)) {
        if (cmd[strlen(cmd) - 1] == '\n') {
            cmd[strlen(cmd) - 1] = '\0';
        }

        // 创建子进程
        // Clone the calling process, creating an exact copy.
        // Return -1 for errors, 0 to the new process,
        // and the process ID of the new process to the old process.
        pid = fork();
        if (pid < 0) {
            perror("创建子进程失败");
            // 0 代表进程创建成功
        } else if (pid == 0) {
            // printf("这是子进程");
            execlp(cmd, cmd, (char *)0);
            exit(127);
        }
        // else {
        //     printf("这是父进程");
        // }

        if ((pid = waitpid(pid, &status, 0)) < 0) {
            perror("等待子进程失败");
        }

        // 输出%等待下一次输入
        printf("%% ");
    }
    exit(0);
}