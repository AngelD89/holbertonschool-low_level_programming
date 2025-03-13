#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Returns a pointer to a newly allocated space in memory,
 *           containing a copy of the string given as a parameter.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL if str is NULL
 *         or if memory allocation fails.
 */
char *_strdup(char *str)
{
	char *duplicate;
	unsigned int length = 0;
	unsigned int i;

	/* Return NULL if str is NULL */
	if (str == NULL)
		return (NULL);

	/* Calculate the length of the string */
	while (str[length] != '\0')
		length++;
	/* Allocate memory for the duplicate string (+1 for the null terminator) */
	duplicate = malloc(sizeof(char) * (length + 1));

	/* Check if malloc failed */
	if (duplicate == NULL)
		return (NULL);

	/* Copy the string into the newly allocated memory */
	for (i = 0; i <= length; i++)
		duplicate[i] = str[i];

	/* Return the pointer to the duplicated string */
	return (duplicate);
}
