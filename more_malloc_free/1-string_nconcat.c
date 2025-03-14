#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 * @n: Number of bytes of s2 to concatenate.
 *
 * Return: Pointer to newly allocated memory containing s1 followed by
 *         the first n bytes of s2, and null-terminated. Returns NULL if
 *         memory allocation fails.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1, len2, n_bytes, i, j;
	char *result;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = strlen(s1);
	len2 = strlen(s2);

	n_bytes = (n >= len2) ? len2 : n;
	result = malloc(len1 + n_bytes + 1);
	if (result == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		result[i] = s1[i];

	for (j = 0; j < n_bytes; j++)
		result[i + j] = s2[j];

	result[i + j] = '\0';
	return (result);
}
