#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int mails;

/**
 * routine - this function increases the mail variable a million times
 * 
 * Return: 100000.
*/
void *routine()
{
    int i;

    for (i = 0; i < 100000; i++)
    {
        mails++;
        //read mails
        //increment
        //write mails
    }
}

/**
 * main - this program implements a race condition. 
*/
int main(int argc, char *argv[])
{
    pthread_t p1, p2;

    if (pthread_create(&p1, NULL, &routine, NULL) != 0)
    {
        return (1);
    }
    if (pthread_create(&p2, NULL, &routine, NULL) != 0)
    {
        return (2);
    }
    if (pthread_join(p1, NULL) != 0)
    {
        return (3);
    }
    if (pthread_join(p2, NULL) != 0)
    {
        return (4);
    }

    printf("Number of mails: %d\n", mails);
    return (0);
}