#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define THREAD_NUM 4

pthread_mutex_t mutexFuel;
int fuel = 50;
pthread_mutex_t mtexWater;
int water = 10;

void *routine(void *args)
{
	if (rand() % 2 == 0)
	{
		pthread_mutex_lock(&mutexFuel);
		sleep(1);
		pthread_mutex_lock(&mutexWater);
	} else {
		pthread_mutex_lock(&mutexWater);
		sleep(1);
		pthread_mutex_lock(&mutexFuel);
	}
	fuel += 50;
	water = fuel;
	printf("Incremented fuel to: %d set water to %d\n", fuel, water);
	pthread_mutex_unlock(&mutexFuel);
	pthread_mutex_unlock(&mutexWater);
}

/**
 *
 */
int main(int argc, char *argv[])
{
	pthread_t th[THREAD_NUM];
	pthread_mutex_init(&mutexFuel, NULL);
	pthread_mutex_init(&mutexWater, NULL);

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
	printf("fuel: %d\n", fuel);
	printf("water: %d\n", water);
	pthread_mutex_destroy(&mutexFuel);
	pthread_mutex_destroy(&mutexWater);
	return (0);
}
