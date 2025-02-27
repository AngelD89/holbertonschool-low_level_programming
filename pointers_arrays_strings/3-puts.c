#include "main.h"
#include <stdio.h>

/**
 * _puts - Prints a string followed by a new line
 *@str: Pointer to the string to print
 */
void _puts(char *str)
{
	while (*str)
	{
		putchar(*str);
		str++;
	}
	putchar('\n');
}
