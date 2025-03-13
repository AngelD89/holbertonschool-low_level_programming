#include "main.h"
#include <stdlib.h>

/**
 * create_array - Creates array of chars and initializes it with a char.
 * @size: The size of the array to create.
 * @c: The char to initialize the array with.
 *
 * Return: Pointer to array, or NULL if size = 0 or if memory allocation fails.
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	/* Return NULL if size is 0 */
	if (size == 0)
		return (NULL);

	/* Allocate memory for the array */
	array = malloc(sizeof(char) * size);

	/* Check if malloc failed */
	if (array == NULL)
		return (NULL);

	/* Initialize the array with the specified char */
	for (i = 0; i < size; i++)
		array[i] = c;

	/* Return the pointer to the array */
	return (array);
}
