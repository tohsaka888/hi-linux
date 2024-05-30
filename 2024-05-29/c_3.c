#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	char buf[100];
	int fd;
	fd = open(".project", O_RDONLY);
	size_t size = read(fd, buf, 100);
	printf("BUF: %s\n", buf);
	if(size < 0)
	{
		printf("Error reading file\n");
	}
	fd = open("text.txt", O_WRONLY | O_TRUNC);
	size = write(fd, buf, size);
	if(size < 0)
	{
		printf("Error writing file\n");
	}
	fd = open("text.txt", O_RDWR | O_APPEND);
	// O_APPEND后lseek不生效
	lseek(fd, 10, SEEK_SET);
	write(fd, buf, sizeof(buf));
	close(fd);
}
