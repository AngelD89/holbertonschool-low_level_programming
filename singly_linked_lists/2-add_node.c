#include <stdlib.h>
#include <string.h>
#include "lists.h"


/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: pointer to the pointer of the head node
 * @str: string to duplicate and add to the new node
 *
 * Return: pointer to the new node or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	char *dup_str;
	unsigned int len = 0;

	if (str == NULL)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	dup_str = strdup(str);
	if (dup_str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	while (str[len] != '\0')
		len++;

	new_node->str = dup_str;
	new_node->len = strlen(str);
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
