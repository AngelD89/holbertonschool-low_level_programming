#include "main.h"
/**
 * print_alphabet - prints the alphabet in lowercase, follwed by a new line.
 *
 */
void print_alphabet(void)
{
	int n;

	for (n = 97; n <= 122; n++)
	{
		_putchar(n);
	}
	_putchar('\n');
}
