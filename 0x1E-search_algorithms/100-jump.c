#include "search_algos.h"
#include <math.h>

/**
 * jump_search - jump search algorithm for arrays.
 * @array: A pointer to inputed array.
 * @size: The size of array.
 * @value: The value to search for.
 * Return: The index of the value into the array.
 */

int jump_search(int *array, size_t size, int value)
{
	size_t a = 0;
	size_t jump = 0;
	size_t step = sqrt(size);

	if (array == NULL || size == 0)
	{
		return (-1);
	}

	while (jump < size && array[jump] < value)
	{
		a = jump;
		jump += step;
		printf("Value checked array[%lu] = [%d]\n", a, array[a]);
	}
	printf("Value found between indexes [%lu] and [%lu]\n", a, jump);

	while (a < jump)
	{
		printf("Value checked array[%lu] = [%d]\n", a, array[a]);
		if (array[a] == value)
		{
			return (a);
		}
		a++;
	}
	return (-1);
}
