#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int n;
	int m;

	printf("Enter a character: ");
	n = getc(stdin); // 用于从标准输入流（stdin）读取单个字符的函数调用
	m = putc(n, stdout); // 用于向标准输出流（stdout）写入单个字符的函数调用
	// printf("\n");

	// EOF:指示文件结束或发生错误  如果到达文件末尾或者发生错误，这些函数会返回
	// EOF。在输出操作中，如果写入字符失败，也会返回 EOF
	if(n != EOF)
	{
		if(m == EOF)
		{
			perror("output error");
		}
	}

	// 检查指定文件流（如标准输入流stdin）的错误指示器
	if(ferror(stdin))
	{
		perror("input error");
	}
	printf("\n");
	exit(0);
}