#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define THREAD_NUM 4

/**
 * task - struct containing function pointer.
 */
typedef struct Task
{
	void (*taskFunction)(int, int);
	int arg1, arg2;
} Task;

pthread_mutex_t mutexQueue;
pthread_cond_t condQueue;

Task taskQueue[256];
int taskCount = 0;

/**
 * sum - sum a and b and prints it.
 *
 * @a: int
 * @b: int
 * Return: nothing.
 */
void sum(int a, int b)
{
	int sum;

	sum = a + b;
	printf("Sum of %d and %d is %d  respectively\n", a, b, sum);
}

/**
 * product - multiplies two numbers a and b
 *
 * @a: int
 * @b: int 
 * Return: nothing.
 */
void product(int a, int b)
{
	int product;

	product = a * b;
	printf("prod of %d and %d is %d respectively\n", a, b, product);
}

/**
 * executeTask - executes a task and prints the result.
 * @task: pointer to values to be executed.
 *
 * Return: nothing.
 */
void executeTask(Task *task)
{
	task->taskFunction(task->arg1, task->arg2);
	//int result = task->a + task->b;
	//printf("The sum %d and %d is %d\n", task->a, task->b, result);
}

/**
 * submitTask - submits a created task.
 * @task: struct cointaing numbers to be submited.
 *
 * Return: nothing.
 */
void submitTask(Task task)
{
	pthread_mutex_lock(&mutexQueue);
	taskQueue[taskCount] = task;
	taskCount++;
	pthread_mutex_unlock(&mutexQueue);
	pthread_cond_signal(&condQueue);
}

/**
 * startthread - this function waits and gets a task and executes it
 *               if it gets one.
 * @args: void pointer.
 * Return: nothing. 
 */
void *startThread(void *args)
{
	while (1)
	{
		Task task;
		
		pthread_mutex_lock(&mutexQueue);
		
		while (taskCount == 0)
		{
			pthread_cond_wait(&condQueue, &mutexQueue);
		}

		int i = 0;
		task = taskQueue[0];

		for (i = 0; i < taskCount - 1; i++)
		{
			taskQueue[i] = taskQueue[i + 1];
		}
		taskCount--;

		pthread_mutex_unlock(&mutexQueue);
		executeTask(&task);
	}
}


/**
 * main - this program creates a thread pool that adds two numbers and prints it.
 *
 * Return: 0 on sucess, any number otherwise.
 */
int main(int argc, char *argv[])
{
	pthread_t th[THREAD_NUM];
	pthread_mutex_init(&mutexQueue, NULL);
	pthread_cond_init(&condQueue, NULL);

	int i;

	for (i = 0; i < THREAD_NUM; i++)
	{
		if (pthread_create(&th[i], NULL, &startThread, NULL) != 0)
		{
			perror("Failed to create the thread");
		}
	}

	srand(time(NULL));
	for (i = 0; i < 100; i++)
	{
		Task t = {
			.taskFunction = i % 2 == 0 ? &sum : &product,
			.arg1 = rand() % 100,
			.arg2 = rand() % 100
		};
		submitTask(t);
	}

	for (i = 0; i < THREAD_NUM; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
		{
			perror("Failed to join the thread");
		}
	}
	pthread_mutex_destroy(&mutexQueue);
	pthread_cond_destroy(&condQueue);

	return (0);
}
