#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

/**
 * routine - prints a single prime at a time.
 * 
 * Return: nothing.
*/
void *routine(void *arg)
{
    int index = *(int *)arg;
    printf("%d ", primes[index]);
    free(arg);
}
/**
 * main - this program prints a single prime at a time in a
 *        different thread 10 times.
 * 
 * Return: 0 on sucess, any number otherwise.
*/
int main(int argc, char *argv[])
{
    pthread_t th[10];
    int i;

    for (i = 0; i < 10; i++)
    {
        int *a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, &a) != 0)
        {
            perror("Failed to create thread");
        }
    }
    for (i = 0; i < 10; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Failed to join thread");
        }
    }
    return (0);
}