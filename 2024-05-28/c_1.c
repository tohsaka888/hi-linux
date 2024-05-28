#include <dirent.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2) perror("usage: ls directory_name");

    // cannot open
    if ((dp = opendir(argv[1])) == NULL) {
        printf("can't open %s", argv[1]);
    }

    while ((dirp = readdir(dp)) != NULL) {
        printf("%s ", dirp->d_name);
    }

    closedir(dp);
    return 0;
}