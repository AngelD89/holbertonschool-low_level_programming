#include "function_pointers.h"

/**
 * int_index - searches for integer in an array.
 * @array: The integer array to search.
 * @size: The number of elements in the array.
 * @cmp: A pointer yo the comparison function.
 *
 * Return: The index of the first matching element, or -1 if no match or error.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
			return (i);
	}

	return (-1);
}
