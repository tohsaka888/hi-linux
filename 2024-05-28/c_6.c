#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void set_fl(int fd, int flags, int mode)
{
	int val = fcntl(fd, F_GETFL, 0);
	printf("val = %d\n", val);
	if(val < 0)
	{
		printf("fcntl(F_GETFL) failed\n");
		exit(1);
	}

	if(mode == 0)
	{
		// 位或运算将val更新为flag
		// val = 0100 flag = 1011
		// val = 1111
		// 同为0才取0 只要flag有1为为1 就更新为1
		val |= flags;
	}
	else
	{
		val &= ~flags;
	}

	if(fcntl(fd, F_SETFL, val) < 0)
	{
		printf("fcntl(F_SETFL) failed\n");
		exit(1);
	}
	val = fcntl(fd, F_GETFL, 0);
	printf("val = %d\n", val);
}

int main()
{
	int fd = open("test3.txt", O_RDWR);
	// 遗憾的是，5个访问方式标志
	// （O_RDONLY、O_WRONLY、O_RDWR、O_EXEC以及O_SEARCH）
	// 并不各占1位
	// （如前所述，由于历史原因，前3个标志的值分别是0、1和2。这5个值互斥，一个文件的访问方式只能取这5个值之一）。

	// 可以更改的几个标志是：O_APPEND、O_NONBLOCK、O_SYNC、O_DSYNC、O_RSYNC、O_FSYNC和O_ASYNC。
	set_fl(fd, O_NONBLOCK, 0);
	set_fl(fd, O_APPEND, 0);
}