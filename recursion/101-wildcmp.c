#include "main.h"

/**
 * wildcmp - Compares two strings to check if they can be considered identical
 * @s1: The first string
 * @s2: The second string (can contain the special wildcard '*')
 *
 * Return: 1 if the strings are identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*') /* If wildcard is encountered */
	{
		if (!*s1) /* If s1 is empty, check if remaining s2 is all '*' */
			return (*(s2 + 1) == '\0' ? 1 : wildcmp(s1, s2 + 1));
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	}
	if (!*s1 || !*s2) /* If end of either string is reached */
		return (*s1 == *s2); /* Strings are identical if both reached '\0' */
	if (*s1 != *s2) /* If characters don’t match */
		return (0);

	return (wildcmp(s1 + 1, s2 + 1)); /* Continue comparing next characters */
}
