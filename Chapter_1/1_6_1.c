#include <stdio.h>
#include <unistd.h>

int main(void)
{
    long n;

    n = getpid();  //获取进程ID
    printf("hello world from process ID:%ld\n",n);
}