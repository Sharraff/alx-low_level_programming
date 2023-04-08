#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - function that creates a place in memory
 * @b: size of memory to create
 * Return: pointer to memory created
 */
void *malloc_checked(unsigned int b)
{
	void *mem;

	mem = malloc(b);
	if (mem == NULL)
	{
		exit(98);
	}
	return (mem);
}
