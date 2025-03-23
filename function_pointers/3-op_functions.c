#include "3-calc.h"

/* Addition */
int op_add(int a, int b)
{
	return (a + b);
}

/* Substraction */
int op_sub(int a, int b)
{
	return (a - b);
}

/* Multiplication */
int op_mul(int a, int b)
{
	return (a * b);
}

/* Division */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}

/* Modulo */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
