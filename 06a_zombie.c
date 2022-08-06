#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
void main()
{
    pid_t my_pid, parent_pid, child_pid;
    child_pid = fork();
    if (child_pid < 0)
    {
        printf("Fork Error");
        exit(0);
    }
    if (child_pid == 0)
    {
        parent_pid = getppid();
        my_pid = getpid();
        printf("[CHILD] This is child process\n");
        printf("[CHILD] My pid : %d\n", my_pid);
        printf("[CHILD] parent pid : %d\n", parent_pid);
    }
    else
    {
        parent_pid = getppid();
        my_pid = getpid();
        printf("[PARENT] This is parent process\n");
        printf("[PARENT] My pid : %d\n", my_pid);
        printf("[PARENT] parent pid : %d\n", parent_pid);
        printf("[PARENT] child pid : %d\n", child_pid);
        sleep(10);
        printf("[PARENT] Child pid = %d has ended, but it has an entry in process table. It is a zombie process.\n", child_pid);
    }
}