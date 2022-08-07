#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#define MAXITEMS 5
#define BUFFERSIZE 5
sem_t full, empty;
pthread_mutex_t mutex;
int in = 0, out = 0, buffer[BUFFERSIZE];
void *producer(void *pno)
{
    for (int i = 0; i < MAXITEMS; i++)
    {
        sem_wait(&empty);
        int item = rand() % 100;
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        printf("producer %d insert %d at %d\n", *((int *)pno), item, in);
        in = (in + 1) % BUFFERSIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}
void *consumer(void *pno)
{
    for (int i = 0; i < MAXITEMS; i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        printf("consumer %d remove %d from %d\n", *((int *)pno), item, out);
        out = (out + 1) % BUFFERSIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}
void main()
{
    srand(time(NULL));
    sem_init(&empty, 0, BUFFERSIZE);
    sem_init(&full, 0, 0);
    int i, a[] = {1, 2, 3, 4, 5};
    pthread_t pro[MAXITEMS], con[MAXITEMS];
    for (i = 0; i < MAXITEMS; i++)
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
    for (i = 0; i < MAXITEMS; i++)
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
    for (i = 0; i < MAXITEMS; i++)
        pthread_join(pro[i], NULL);
    for (i = 0; i < MAXITEMS; i++)
        pthread_join(con[i], NULL);
    pthread_mutex_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);
}
