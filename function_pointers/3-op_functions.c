#include "3-calc.h"

/**
 * op_add - Adds two integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: The sum of a and b.
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - Subtracts the second integer from the first.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: The difference of a and b.
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - Multiplies two integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: The product of a and b.
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - Divides the first integer by the second.
 * @a: First integer (numerator).
 * @b: Second integer (denominator).
 *
 * Return: The result of the division (a / b).
 *         If the denominator is 0, prints "Error" and exits with status 100.
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}

/**
 * op_mod - Computes the remainder of the division of two integers.
 * @a: First integer (numerator).
 * @b: Second integer (denominator).
 *
 * Return: The remainder of the division (a % b).
 *         If the denominator is 0, prints "Error" and exits with status 100.
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
