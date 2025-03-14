#include "main.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string, which must have enough space.
 * @src: The source string to append to dest.
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*ptr)
		ptr++;

	while (*src)
		*ptr++ = *src++;

	*ptr++ = '\0';
	return (dest);
}
