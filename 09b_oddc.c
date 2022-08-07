#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/mman.h>
void main(int argc, char *argv[])
{
    int i;
    void *ptr;
    int shmid = shmget((key_t)1122, 4096, 0666);
    ptr = shmat(shmid, NULL, 0666);
    printf("CHILD:\n");
    int n = atoi(argv[1]);
    for (i = 1; i < 2 * n + 1; i += 2)
    {
        sprintf(ptr, "%d ", i);
        printf("%d ", i);
        ptr += strlen(ptr);
    }
    shmctl(shmid, IPC_RMID, NULL);
}
