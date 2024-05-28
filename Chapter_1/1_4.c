#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

void err_quit(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int main(int argc,char *argv[])
{
    DIR   *DP;
    struct dirent    *dirp;

    if (argc != 2)
    {
        err_quit("usage:ls directory_name");
    }

    if ((DP = opendir(argv[1]))==NULL)  //argv[1]是程序运行时传入的第二个参数，即要打开的目录名，"args": ["."],代表当前目录下的所有文件
    {
        printf("canot open %s\n",argv[1]);
        exit(1);
    }
    while ((dirp = readdir(DP))!=NULL)  //用于读取目录中的下一个文件名
    {
        printf("%s ",dirp->d_name);
    }

    printf("\n ");
    closedir(DP);  //关闭先前由 opendir() 打开的目录
    exit(0);
}