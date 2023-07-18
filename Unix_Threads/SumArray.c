#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

/**
 * routine - this function sums an array in two different halfs.
 * 
 * Return: nothing.
*/
void *routine(void *arg)
{
    int index = *(int *)arg;
    int sum = 0;
    int i = 0;

    for (i = 0; i < 5; i++)
    {
        sum += primes[index + i];
    }

    printf("Local sum: %d\n", sum);
    *(int *)arg = sum;
    return (arg);
}
/**
 * main - this program split an array in to two abd compute the 
 *        the sum.
 * 
 * Return: 0 on sucess, any number otherwise.
*/
int main(int argc, char *argv[])
{
    pthread_t th[2];
    int i;

    for (i = 0; i < 2; i++)
    {
        int *a = malloc(sizeof(int));
        *a = i * 5;
        if (pthread_create(&th[i], NULL, &routine, a) != 0)
        {
            perror("Failed to create thread");
        }
    }
    int globalSum = 0; 
    for (i = 0; i < 2; i++)
    {
        int *r;
        if (pthread_join(th[i], (void **) &r) != 0)
        {
            perror("Failed to join thread");
        }
        globalSum += *r;
        free(r);
    }
    printf("Global sum: %d\n", globalSum);
    return (0);
}