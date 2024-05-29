#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 4096

int main()
{
	int n;
	char buf[BUFSIZE];

	while((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0)
	{
		write(STDOUT_FILENO, buf, n);
	}
	return 0;
}