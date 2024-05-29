#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	DIR* dp;
	struct dirent* dirp;

	if(argc != 2)
	{
		printf("usage: ls directory_name");
		exit(1);
	};

	// cannot open
	if((dp = opendir(argv[1])) == NULL)
	{
		printf("can't open %s", argv[1]);
	}

	while((dirp = readdir(dp)) != NULL)
	{
		printf("%s ", dirp->d_name);
	}

	closedir(dp);
	return 0;
}