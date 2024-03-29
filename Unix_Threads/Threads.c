#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

/**
 * routine - function to run inside thread
*/
void *routine()
{
    printf("Test from thread\n");
    sleep(3);
    printf("Ending thread\n");
}
/**
 * main - this program creates two threads and runs a function
 *        inside thr thresds.
 * 
 * Return: 0 on sucess and any number otherwise.
*/
int main(int argc, char *argv[])
{
    pthread_t t1, t2;
    
    if (pthread_create(&t1, NULL, &routine, NULL) != 0)
    {
        return (1);
    }
    if (pthread_create(&t2, NULL, &routine, NULL) != 0)
    {
        return (2);
    }
    if (pthread_join(t1, NULL) != 0)
    {
        return (3);
    }
    if (pthread_join(t2, NULL) != 0)
    {
        return (4);
    }
    return (0);
}