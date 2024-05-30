#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_CACHED_FDS 100

int fake_dup2(int oldfd, int newfd)
{
	close(newfd);
	int cached_fds[MAX_CACHED_FDS];
	int fd_copied;
	int i = 0;

	if(newfd > MAX_CACHED_FDS)
	{
		printf("error: newfd is too large\n");
		exit(1);
	}

	while((fd_copied = dup(oldfd)) != newfd)
	{
		cached_fds[i] = fd_copied;
		i++;
	}

	for(int j = 0; j < i; j++)
	{
		int cached_fd = cached_fds[i];
		close(cached_fd);
	}

	return newfd;
}

int test_fake_dup2(int origin_fd, int copied_fd)
{
	int origin_fd_props, copied_fd_props;
	origin_fd_props = fcntl(origin_fd, F_GETFL);
	fcntl(origin_fd, F_SETFL, origin_fd_props | O_NONBLOCK);
	origin_fd_props = fcntl(origin_fd, F_GETFL);
	copied_fd_props = fcntl(copied_fd, F_GETFL);
	printf("origin fd props: %d\n", origin_fd_props);
	printf("copied fd props: %d\n", copied_fd_props);
	return origin_fd_props == copied_fd_props;
}

int main()
{
	int result = 0;
	int fd = open("file.txt", O_CREAT, S_IRUSR);
	if(fd == -1)
	{
		printf("Error opening file\n");
		return 1;
	}
	int fd1 = fake_dup2(fd, 10);
	result = test_fake_dup2(fd, fd1);
	printf("Result: %d\n", result);
	if(result == 1)
	{
		printf("PASS!");
	}
	else
	{
		printf("FAIL!");
		exit(1);
	}
}