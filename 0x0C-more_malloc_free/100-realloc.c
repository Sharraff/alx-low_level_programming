#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _realloc - reallocates and copies contents from old memory to new
 * @ptr: pointer to old_size
 * @old_size: size of old content
 * @new_size: size of new content
 * Return: new memory location
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i = 0;
	char *new_ptr;
	char *old_ptr = ptr;


	ptr = malloc(old_size);
	new_ptr = malloc(new_size);

	for (i = 0; i < new_size; i++)
	{
		new_ptr[old_size] = old_ptr[i];
	}
	if (new_size > old_size)
	{};
	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
		new_ptr = malloc(new_size);
	if (new_size == 0 && ptr == NULL)
		free(ptr);
	free(ptr);
	return (new_ptr);
}
