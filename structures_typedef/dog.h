#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Defines a new struct for a dog
 * @name: Name of the dog (char pointer)
 * @age: Age of the dog (float)
 * @owner: Owner of the dog (char pointer)
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

typedef struct dog dog_t;

/* Function prototype for init_dog */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif /* DOG_H */
