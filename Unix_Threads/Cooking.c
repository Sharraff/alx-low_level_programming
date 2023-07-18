#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <time.h>

//chefs = threads
//stove = shared data (+mutex)

pthread_mutex_t stoveMutex[4];
int stoveFuel[4] = { 100, 100, 100, 100 };
 
/**
 * routine -
 * 
*/
void *routine(void *args)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        if (pthread_mutex_trylock(&stoveMutex[i]) == 0)
        {
            int fuelNeeded = (rand() % 30);
            if (stoveFuel[i] - fuelNeeded < 0)
            {
                printf("No more fuel...going home\n");
            } else {
                stoveFuel[i] -= fuelNeeded;
                usleep(500000);
                printf("Fuel left %d\n", stoveFuel[i]);
            }
            pthread_mutex_unlock(&stoveMutex[i]);
            break;
        } else {
            if (i == 3)
            {
                printf("No stove available yet, wait...\n");
                usleep(300000);
                i = 0;
            }
        }
    }
}
/**
 * main -
 * 
*/
int main(int argc, char *argv[])
{
    pthread_t th[10];
    srand(time(NULL));
    int i, j;

    for (j = 0; j < 4; i++)
    {
        pthread_mutex_init(&stoveMutex[i], NULL);
    }
    for (i = 0; i < 10; i++)
    {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
        {
            perror("Error at creating thread");
        }
    }
    for (i = 0; i < 10; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Error at joining thread");
        }
    }
    for (j = 0; j < 4; j++)
    {
        pthread_mutex_destroy(&stoveMutex[i]);
    }
    return (0);
}