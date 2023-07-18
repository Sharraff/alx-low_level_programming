#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define THREAD_NUM 2

pthread_mutex_t mutexFuel = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condFuel = PTHREAD_MUTEX_INITIALIZER;

void *routine(void *args)
{}


int main(int argc, char *argv[])
{
	pthread_t th[THREAD_NUM];

	int i;

	for (i = 0; i < THREAD_NUM; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
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
	pthread_mutex_destroy(&mutexFuel);
	return (0);
}
