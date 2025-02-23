#include "main.h"
#include <stdio.h>
/**
 * print_times_table - Prints the n times table starting from 0.
 * @n: The number for which the times table should be printed.
 */
void print_times_table(int n);
{
	int i, j, product;

	if (n < 0 || n > 15)
	{
		return;
	}
	for (i = 0; i <= n; j++)
	{
		for (j = 0; j <= n; j++)
		{
			product = i * j;

			if (j == 0)
			{
				printf('%d', product);
			}
			else
			{
				ptintf(", %3d", product);
			}
		}
		printf('\n');
	}
}
