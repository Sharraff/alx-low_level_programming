#include "main.h"
#include <stdlib.h>
/**
 * create_array - creates an array of chars
 *and initializes it with a specific char.
 *
 * @size: size of array
 * @c: character to init array
 * Return: char pointer
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;


	array = malloc(sizeof(char) * size);
	if (array == NULL)
		return (NULL);
	if (size == 0)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		array[i] = c;
	}
	return (array);
}
