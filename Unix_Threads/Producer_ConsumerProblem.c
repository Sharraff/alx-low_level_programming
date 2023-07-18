#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

//Manage shared memory access
//checking for if buffer if buffer is full
//checking for if buffer is empty

#define THREAD_NUM 2

sem_t semEmpty;
sem_t semFull;

pthread_mutex_t mutexBuffer;

int buffer[10];
int count = 0;

/**
 * producer - this function produces values after every 1 second.
 *
 * Return: nothing.
 */
void *producer(void *args)
{
	while (1)
	{
		//produce
		int x = rand() % 100;
		sleep(1);

		//Add to the buffer
		sem_wait(&semEmpty);
		pthread_mutex_lock(&mutexBuffer);
		buffer[count] = x;
		count++;
		pthread_mutex_unlock(&mutexBuffer);
		sem_post(&semFull);
	}
}
/**
 * consumer - this function conssumes what the producer produces
 *            after every one second.
 *
 * Return: nothing.
 */
void *consumer(void *args)
{
	while (1)
	{
		int y;

		//remove from the buffer
		sem_wait(&semFull);
		pthread_mutex_lock(&mutexBuffer);
		y = buffer[count - 1];
		count--;
		pthread_mutex_unlock(&mutexBuffer);
		sem_post(&semEmpty);
		
		//consume
		printf("Got %d\n", y);
		sleep(1);
	}
}

/**
 * main - this program solves the producer/consumer problem in a multithreaded
 *        fashion.
 *
 * Return: 0 on sucess, any number otherwise.
 */
int main(int argc, char *argv[])
{
	pthread_t th[THREAD_NUM];
	pthread_mutex_init(&mutexBuffer, NULL);

	sem_init(&semEmpty, 0, 10);
	sem_init(&semFull, 0, 0);

	srand(time(NULL));
	int i;

	for (i = 0; i < THREAD_NUM; i++)
	{
		if (i > 0)
		{
			if (pthread_create(&th[i], NULL, &producer, NULL) != 0)
			{
				perror("Failed to create thread");
			}
		} else {
			if (pthread_create(&th[i], NULL, &consumer, NULL) != 0)
			{
				perror("Failed to create thread");
			}
		}
	}
	for (i = 0; i <THREAD_NUM; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
		{
			perror("Failed to join thread");
		}
	}

	sem_destroy(&semEmpty);
	sem_destroy(&semFull);

	pthread_mutex_destroy(&mutexBuffer);
	return (0);
}
