#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>


/**
 * roll_dice - simulate rolling of a dice and return the result.
 * 
 * Return: the result.
*/
void *roll_dice()
{
    int value = (rand() % 6) + 1;
    int *result = malloc(sizeof(int));
    *result = value;
    //printf("%d\n", value);
    printf("Thread result: %p\n", result);
    return (void *) result;
}

/**
 * main - this  program demonstrates how to receieve a return
 *        value in a thread.
 * 
 * Return: 0 on sucess, any other number otherwise.
*/
int main(int argc, char *argv[])
{
    int *res;
    pthread_t th;
    srand(time(NULL));

    if (pthread_create(&th, NULL, &roll_dice, NULL) != 0)
    {
        return (1);
    }
    if (pthread_join(th,(void **) &res) != 0)
    {
        return (2);
    }
    printf("Main res: %p\n", res);
    printf("Result: %d\n", *res);
    free(res);

    return (0);
}