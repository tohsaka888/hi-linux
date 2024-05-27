// 从标准输入读命令并执行
#include <stdio.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

int main() {
    char cmd[MAX_CMD_LEN];
    pid_t pid;
    int status;

    // 需要%%才能正确显示%
    printf("%% ");

    // 从stdin中读取命令（回车终止）
    while (fgets(cmd, sizeof(cmd), stdin)) {
        if (cmd[sizeof(cmd) - 1] == '\n') {
            cmd[sizeof(cmd) - 1] = '\0';
        }

        // 创建子进程
        pid = fork();
        if (pid < 0) {
            perror("创建子进程失败");
        } else  {
            execlp(cmd, cmd, NULL);
        }
    }
}