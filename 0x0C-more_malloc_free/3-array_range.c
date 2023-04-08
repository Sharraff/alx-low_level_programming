#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 *
 */
int *array_range(int min, int max)
{
	int n = 0;
	int i = 0;
	int *arr;


	n = max - min;
	arr = malloc(sizeof(int) * n);

	for (i = 0; i <= n; i++)
		arr[i] = min++;

	return (arr);
}
