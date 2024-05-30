
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
	int i;
	struct stat buf;
	char* ptr;

	for(i = 1; i < argc; i++)
	{
		printf("File: %s\n", argv[i]);
		// lstat函数用于返回一个文件或目录的详细信息，
		// 这些信息被存储在一个名为buf的结构体中。
		if(lstat(argv[i], &buf) < 0)
		{
			printf("lstat error\n");
			continue;
		}
		if(S_ISREG(buf.st_mode))
		{
			ptr = "regular";
		}
		else if(S_ISDIR(buf.st_mode))
		{
			ptr = "directory";
		}
		else if(S_ISLNK(buf.st_mode))
		{
			ptr = "symbolic link";
		}
		else if(S_ISFIFO(buf.st_mode))
		{
			ptr = "FIFO";
		}
		else if(S_ISCHR(buf.st_mode))
		{
			ptr = "character special device";
		}
		else if(S_ISSOCK(buf.st_mode))
		{
			ptr = "socket";
		}
		else
		{
			ptr = "unknown";
		}
		printf("Type: %s\n", ptr);
	}
	return 0;
}