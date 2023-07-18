#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>


pthread_barrier_t barrier;
/**
 * routine - this function sets a barrier_wait.
 * 
 * Return: nothing.
*/
void *routine(void *args)
{
    while (1)
    {
        printf("waiting at the barrier...\n");
        pthread_barrier_wait(&barrier);
        printf("We passed the barrier\n");
        sleep(1);
    }
}

/**
 * main - this program implements a barrier for three threads
 * 
 * Return: 0 on success, any number otherwise.
*/
int main(int argc, char *argv[])
{
    pthread_t th[3];
    int i;
    pthread_barrier_init(&barrier, NULL, 3);

    for (i = 0; i < 3; i++)
    {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
        {
            perror("Failed to create thread");
        }
    }
    for (i = 0; i < 3; i++)
    {
        /* code */
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Failed to join thread");
        }
    }
    pthread_barrier_destroy(&barrier);
    return (0);
}