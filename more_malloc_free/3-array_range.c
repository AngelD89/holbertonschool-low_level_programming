#include <stdlib.h>
#include <stdio.h>

/**
 * array_range - Creates an array of integers from min to max
 * @min: The starting value of the array
 * @max: The ending value of the array
 *
 * Return: Pointer to the newly created array, or NULL on failure
 */
int *array_range(int min, int max)
{
	int *arr;
	int i, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);

	for (i = 0; i < size; i++)
		arr[i] = min + i;

	return (arr);
}
