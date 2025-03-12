#include "main.h"

/**
 * _strlen_recursion - Returns the length of a string
 * @s: The string to measure
 *
 * Return: The length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0') /* Base case: end of string */
		return (0);
	return (1 + _strlen_recursion(s + 1)); /* Count char and move forward */
}

/**
 * check_palindrome - Checks if a string is a palindrome recursively
 * @s: The string to check
 * @left: The left index
 * @right: The right index
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int check_palindrome(char *s, int left, int right)
{
	if (left >= right) /* Base case: pointers have met or crossed */
		return (1);
	if (s[left] != s[right]) /* If characters don't match, not a palindrome */
		return (0);
	return (check_palindrome(s, left + 1, right - 1)); /* Move inward */
}

/**
 * is_palindrome - Determines if a string is a palindrome
 * @s: The string to check
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = _strlen_recursion(s); /* Get the length of the string */

	if (len == 0) /* An empty string is a palindrome */
		return (1);

	return (check_palindrome(s, 0, len - 1)); /* Start checking from both ends */
}
