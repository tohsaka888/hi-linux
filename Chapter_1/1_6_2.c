/*从标准输入读命令并执行*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    char buf[BUFSIZ];
    pid_t pid;
    int status;

    printf("%% ");  //%后跟输入命令，ex：ls,date,pwd
    while (fgets(buf,BUFSIZ,stdin) != NULL)  //从标准输入（通常是键盘）读取最多 BUFSIZ - 1 个字符到缓冲区 buf 中，直到遇到换行符或者文件结束符为止
    {
        if (buf[strlen(buf) - 1] == '\n')   //通过strlen算出buf长度，并判断倒数第二个字符是否为'\n',并将其替换为'\0'
        {
            buf[strlen(buf) - 1] = '\0';
        }
        
        pid = fork();
        if (pid < 0)   //fork()创建一个新进程，此进程为子进程
        {
            perror("fork error");
        }
        else if (pid == 0)   //正在运行子进程    //pid已在if条件中创建，再else中再次调用fork，会导致多余的子进程创建
        {
            execlp(buf,buf,(char *)0);  //获取buf中的指令，并运行
            exit(127);  //如果 execlp() 函数执行失败（即无法找到要执行的命令），子进程会以状态码 127 退出
                               //127，它通常被用来表示“命令未找到”或者“命令无法执行”的意思
        }
        //if (pid = fork())>0,则表示正在运行父进程，并且返回值是子进程的ID

        if ((pid = waitpid(pid,&status,0)) < 0)
        {
            perror("waitpid error");
        }
        printf("%% ");         
    }
    exit(0);
}