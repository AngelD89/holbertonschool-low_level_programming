#include "dog.h"
#include <stdlib.h>
#include <string.h>

/**
 * new_dog - Creates a new dog
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 *
 * Return: Pointer to the new dog_t structure, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_d;

	if (name == NULL || owner == NULL)
		return (NULL);

	new_d = malloc(sizeof(dog_t));
	if (new_d == NULL)
		return (NULL);

	new_d->name = malloc(strlen(name) + 1);
	if (new_d->name == NULL)
	{
		free(new_d);
		return (NULL);
	}
	strcpy(new_d->name, name);

	new_d->owner = malloc(strlen(owner) + 1);
	if (new_d->owner == NULL)
	{
		free(new_d->name);
		free(new_d);
		return (NULL);
	}
	strcpy(new_d->owner, owner);

	new_d->age = age;

	return (new_d);
}
