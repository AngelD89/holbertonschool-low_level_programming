#include "function_pointers.h"

/**
 * print_name - Prints a name using the function pointer provided.
 * @name: The name to be printed.
 * @f: A pointer to a function that takes a char * and returns nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}
