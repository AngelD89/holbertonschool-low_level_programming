#include "main.h"
#include <stdio.h>
/**
 * print_times_table - Prints the n times table starting from 0.
 * @n: The number for which the times table should be printed.
 */
void print_times_table(int n)
{
	int i, j, product;

	if (n < 0 || n > 15)
		return;

	for (i = 0; i <= n; j++)
	{
		for (j = 0; j <= n; j++)
		{
			product = i * j;

			if (j == 0)
				_putchar('0' + product);
			else
			{
				_putchar(',');
				_putchar(' ');
				if (product < 10)
					_putchar(' ');
				if (product < 100)
					_putchar(' ');
				printf("%d", product);
			}
		}
		_putchar('\n');
	}
}
