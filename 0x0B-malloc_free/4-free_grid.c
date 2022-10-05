#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2 dimentional grid previously created
 * by alloc_grid function
 *
 * @grid:double pointer to 2d array
 * @height: array height
 * Return: nothing
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);
	free(grid);
}
