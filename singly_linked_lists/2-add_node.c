#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: double pointer to the head of the list
 * @str: string to duplicate into the new node.
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	char *duplicate_str;
	int len;

	if (!str)
		return (NULL);

	duplicate_str = strdup(str);
	if (!duplicate_str)
		return (NULL);

	for (len = 0; duplicate_str[len]; len++)
		;

	new_node = malloc(sizeof(list_t));
	if (!new_node)
	{
		free(duplicate_str);
		return (NULL);

	}

	new_node->str = duplicate_str;
	new_node->len = len;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
