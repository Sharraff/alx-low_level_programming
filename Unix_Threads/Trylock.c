#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

pthread_mutex_t mutex;

/**
 *  routine - this function implements a trylock.
 * 
 *  Return: nothing.
*/
void *routine(void *arg)
{
    if (pthread_mutex_trylock(&mutex) == 0)
    {
        printf("Got lock\n");
        sleep(1);
        pthread_mutex_lock(&mutex);
    } else{
        printf("Didn't get lock\n");
    }
}
/**
 * main - this program implements a trylock.
 * 
 * Return: 0 on sucess, any number otherwise
*/
int main(int argc, char *argv[])
{
    pthread_t th[4];
    pthread_mutex_init(&mutex, NULL);
    int i;

    for (i = 0; i < 4; i++)
    {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
        {
            perror("Error at creating thread");
        }
    }
    for (i = 0; i < 4; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Error at joining thread");
        }
    }
    return (0);
}