#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: A pointer to the newly allocated concatenated string,
 *         or NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	unsigned int len1 = 0, len2 = 0;
	unsigned int i, j;

	/* Treat NULL as an empty string */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calculate the length of s1 */
	while (s1[len1] != '\0')
		len1++;

	/* Calculate the length of s2 */
	while (s2[len2] != '\0')
		len2++;

	/* Allocate memory for the concatenated string (+1 for the null terminator) */
	concat = malloc(sizeof(char) * (len1 + len2 + 1));

	/* Check if malloc failed */
	if (concat == NULL)
		return (NULL);

	/* Copy s1 into the concatenated string */
	for (i = 0; i < len1; i++)
		concat[i] = s1[i];

	/* Copy s2 into the concatenated string */
	for (j = 0; j < len2; j++)
		concat[i + j] = s2[j];

	/* Add the null terminator */
	concat[i + j] = '\0';

	/* Return the pointer to the concatenated string */
	return (concat);
}
