#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    //getuid() 是一个系统调用，用于获取当前进程的用户 ID。
    //getgid() 是一个系统调用，用于获取当前进程所属的组 ID
    printf("uid = %d, gid = %d\n,",getuid(),getgid());  //验证ID是否正确，打印命令行：id，即可看到用户ID和组ID
    exit(0);
}