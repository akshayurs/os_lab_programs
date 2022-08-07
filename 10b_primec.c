#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int i, j, flag;
    void *ptr;
    int shm_fd = shm_open("OS", O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, 4096);
    ptr = mmap(0, 4096, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    printf("CHILD:\n");
    int m = atoi(argv[1]), n = atoi(argv[2]);

    for (i = m; i <= n; i++)
    {
        if (i < 2)
            continue;
        flag = 1;
        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            sprintf(ptr, "%d ", i);
            printf("%d ", i);
            ptr += strlen(ptr);
        }
    }
}