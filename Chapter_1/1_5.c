#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define buffsize 4096

int main(void)
{
	int n;
	int m;
	int buff[buffsize];

	n = read(STDIN_FILENO, buff, sizeof(buff)); // 使用 STDIN_FILENO 作为参数来读取标准输入流的数据
	m = write(STDOUT_FILENO, buff, n); // 使用 STDOUT_FILENO 作为参数来将消息写入到标准输出流。
	if(n > 0)
	{
		if(m != n)
		{
			perror("write error");
		}
	}
	if(n < 0)
	{
		perror("read error");
	}
}