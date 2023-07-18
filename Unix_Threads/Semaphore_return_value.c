#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define THREAD_NUM 4

sem_t semaphore;

/**
 * routine - this function prints an argument from a thread
 *
 * Return: nothing.
 */
void *routine(void *args)
{
	int index = *(int *)args;
	int semVal;

	sem_wait(&semaphore);
	sleep(index + 1);
	sem_getvalue(&semaphore, &semVal);
	printf("(%d) Current semaphore value after waits is %d\n", index, semVal);
	sem_getvalue(&semaphore, &semVal);
	printf("(%d) Current semaphore value after post is %d\n", index, semVal);
	sem_post(&semaphore);
	free(args);
}
/**
 * main - this program implements a semaphore.
 *
 * Return: 0 on sucess, any number otherwise.
 */
int main(int argc, char *argv[])
{
	pthread_t th[THREAD_NUM];
	sem_init(&semaphore, 0, 4);

	int i;

	for (i = 0; i < THREAD_NUM; i++)
	{
		int *a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
		{
			perror("Failed to create thread");
		}
	}
	for (i = 0; i < THREAD_NUM; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
		{
			perror("Failed to join thread");
		}
	}
	sem_destroy(&semaphore);
	return (0);
}
