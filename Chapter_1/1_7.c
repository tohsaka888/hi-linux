#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

/*errno 是一个特殊的全局变量，用于表示最近发生的错误代码。通过将 errno 设置为特定的错误码，可以模拟某个操作或函数调用遇到了相应的错误。*/
/*note:直接设置 errno 的值是一种模拟错误场景的方法，并不会真正触发底层系统产生相应的错误。要触发实际的系统错误并设置真实的 errno 值，
       需要调用可能会失败并设置 errno 的系统调用或库函数*/

int main(int argc,char *argv[])
{
    //将错误消息输出到标准错误流(stderr),strerror(EACCES) 返回与给定错误码 EACCES 相关联的错误消息字符串
    fprintf(stderr,"EACCES:%s\n",strerror(EACCES));  //EACCES:表示产生了权限问题，没有足够的权限打开请求文件
    errno = EACCES;  //errno 设置为 EACCES 表示模拟程序遇到了 "Permission denied"（权限被拒绝）的错误
    perror(argv[0]);  //打印与当前错误码相关联的错误消息
    exit(0);
}