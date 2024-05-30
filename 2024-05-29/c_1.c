#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd, fd_cp;
	int fd_copy_props, fd_props;
	if(fd < 0)
	{
		printf("cannot open file\n");
	}
	fd = open("text.txt", O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	fd_cp = dup(fd);
	fd_props = fcntl(fd, F_GETFL, 0);
	printf("origin fd's props: %d\n", fd_props);

	printf("set origin fd to append\n");
	fcntl(fd, F_SETFL, fd_props | O_APPEND);
	fd_copy_props = fcntl(fd_cp, F_GETFL, 0);
	fd_props = fcntl(fd, F_GETFL, 0);
	printf("copy fd's props: %d\n", fd_copy_props);
	printf("origin fd's props: %d\n", fd_props);
}