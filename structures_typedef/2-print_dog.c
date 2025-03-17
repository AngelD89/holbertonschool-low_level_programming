#include <stdio.h>
#include <stddef.h>
#include "dog.h"

/**
 * print_dog - Prints the attributes of a dog structure
 * @d: Pointer to struct dog
 *
 * Description: Prints the dog's name, age, and owner.
 * If a field is NULL, it prints "(nil)" instead.
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	/* Print name, replacing NULL with "(nil)" */
	if (d->name == NULL)
		printf("Name: (nil)\n");
	else
		printf("Name: %s\n", d->name);

	/* Print age */
i	printf("Age: %f\n", d->age);

	/* Print owner, replacing NULL with "(nil)" */
	if (d->owner == NULL)
		printf("Owner: (nil)\n");
	else
		printf("Owner: %s\n", d->owner);
}
