#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;
int fuel = 0;
/**
 * fuel_filling - this function adds 15 units of fuel every loop
 *                loop iteration.
 *
 * Return: nothing.
*/
void *fuel_filling(void *arg)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&mutexFuel);
        fuel += 15;
        printf("Filled fuel... %d\n", fuel);
        pthread_mutex_unlock(&mutexFuel);
        pthread_cond_signal(&condFuel);
        sleep(1);
    }
}

/**
 * car - this function reduces 40 units of fuel. 
 * 
 * Return: nothing.
*/
void *car(void *arg)
{
    pthread_mutex_lock(&mutexFuel);
    while (fuel < 40)
    {
        /* code */
        printf("No fuel. Waiting...\n");
        pthread_cond_wait(&condFuel, &mutexFuel);
        //Equivalent
        //pthead_mutex_unlock(&mutexFuel)
        //wait for signal on condfuel
        //pthread_mutex_lock(&mutexFuel)

    }
    fuel -= 40;
    printf("Got fuel. Now left: %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
}


/**
 * main - this program implements a condition variable with two threads,
 *        to fuel a car.
 * Return: 0 on succes, any number orderwise. 
*/
int main(int argc, char *argv[])
{
    pthread_t th[2];
    int i = 0;
    int j = 0;
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&condFuel, NULL);

    for (i = 0; i < 2; i++)
    {
        if (i == 1)
        {
            if (pthread_create(&th[i], NULL, &fuel_filling, NULL) != 0)
            {
                perror("Failed to create thread");
            } else {
                if (pthread_create(&th[i], NULL, &car, NULL) != 0)
                {
                    perror("Failed to thread");
                }
            }
        }
        return (0);
    }
    for (j = 0; j < 2; j++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Failed to join thread");
        }
    }
    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&condFuel);
}