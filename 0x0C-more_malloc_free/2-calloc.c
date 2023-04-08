#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _calloc - function that allocates memory to arrsys
 * @nmemb: number of elements in array
 * @size: size of each element
 * Return: pointer to memory alocated
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *arr;

	for (i = 0; i < nmemb; i++)
	{
		arr = malloc(size);
	}
	if (nmemb == 0 || size == 0)
		return (NULL);
	if (arr == NULL)
		return (NULL);

	return (arr);
}

