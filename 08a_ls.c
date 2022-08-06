#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
void main(int argc, char *argv[])
{
    DIR *d;
    struct dirent *dir;
    if (argc != 2)
    {
        printf("Pass directory name as argument\n");
        exit(0);
    }
    if ((d = opendir(argv[1])) == NULL)
    {
        printf("Failed to open directory\n");
        exit(0);
    }
    while ((dir = readdir(d)) != NULL)
    {
        printf("%s\n", dir->d_name);
    }
}