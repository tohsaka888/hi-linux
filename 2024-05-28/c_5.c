#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
	int val;
	if(argc < 2)
	{
		printf("usage: a.out <descriptor#>");
        exit(1);
    }
	val = fcntl(atoi(argv[1]), F_GETFL, 0);
	if(val < 0)
	{
		printf("fcntl error for fd %d", atoi(argv[1]));
        exit(1);
    }
	switch(val & O_ACCMODE)
	{
		case O_RDONLY:
			printf("read only");
			break;
		case O_WRONLY:
			printf("write only");
			break;
		case O_RDWR:
			printf("read write");
			break;
		default:
			printf("unknown mode");
	}

	if(val & O_APPEND)
	{
		printf(", append");
	}
	if(val & O_NONBLOCK)
	{
		printf(", non-blocking");
	}
	if(val & O_SYNC)
	{
		printf(", synchronous writes");
	}
}