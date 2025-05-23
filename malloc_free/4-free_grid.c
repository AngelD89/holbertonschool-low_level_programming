#include <stdlib.h>
#include "main.h"

/**
 * free_grid - frees a 2-dimensional grid created by alloc_grid
 * @grid: pointer to the 2D grid
 * @height: number of rows in the grid
 *
 * Return: Nothing
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL || height <= 0)
		return;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	free(grid);
}
