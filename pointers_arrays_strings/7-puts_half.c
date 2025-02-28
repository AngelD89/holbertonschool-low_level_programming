#include "main.h"

/**
 * puts_half - Prints the second half of a string.
 * @str: The string to process.
 */
void puts_half(char *str)
{
	int len = 0, n;

	while (str[len])
		len++;

	n = (len + 1) / 2;

	while (str[n])
	{
		_putchar(str[n]);
		n++;
	}
	_putchar('\n');
}
