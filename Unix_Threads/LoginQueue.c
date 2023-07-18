#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define THREAD_NUM 16

sem_t semaphore;

/**
 * routine - prints the login state of a user in a server. inthe queue, logged in
 *           or logged out.
 *
 * Return: nothing.
 */
void *routine(void *args)
{
	printf("(%d) waiting in the login queue\n", *(int *)args);
	sem_wait(&semaphore);
	printf("(%d) Logged in\n", *(int *)args);
	sleep(rand() % 5 + 1);
	printf("(%d) Logged out\n", *(int *)args);
	sem_post(&semaphore);
	free(args);
}
/**
 * main - this program implement a login queue
 *
 * Return: 0 on sucess, any number otherwise.
 */
int main(int argc, char *argv[])
{
	pthread_t th[THREAD_NUM];
	sem_init(&semaphore, 0, 12);

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
