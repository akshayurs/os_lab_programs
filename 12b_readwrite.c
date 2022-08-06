#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t wrt;
pthread_mutex_t mutex;
int cnt = 1;
int num_reader = 0;
void *writer(void *wno)
{
    sem_wait(&wrt);
    cnt = cnt * 2;
    printf("Writer %d modified cnt to %d\n", *((int *)wno), cnt);
    sem_post(&wrt);
}
void *reader(void *rno)
{
    pthread_mutex_lock(&mutex);
    num_reader++;
    if (num_reader == 1)
        sem_wait(&wrt);
    pthread_mutex_unlock(&mutex);
    printf("Reader %d reads cnt as %d \n", *((int *)rno), cnt);
    pthread_mutex_lock(&mutex);
    num_reader--;
    if (num_reader == 0)
        sem_post(&wrt);
    pthread_mutex_unlock(&mutex);
}
void main()
{
    pthread_t write[10], read[10];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt, 0, 1);
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;
    for (i = 0; i < 10; i++)
    {
        pthread_create(&write[i], NULL, (void *)writer, (void *)&a[i]);
        pthread_create(&read[i], NULL, (void *)reader, (void *)&a[i]);
    }
    for (i = 0; i < 10; i++)
    {
        pthread_join(write[i], NULL);
        pthread_join(read[i], NULL);
    }
    sem_destroy(&wrt);
    pthread_mutex_destroy(&mutex);
}