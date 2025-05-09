#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: double pointer to the head of the list
 * @str: string to duplicate into the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *temp;
	char *duplicate_str;
	int len = 0;

	if (!str)
		return (NULL);

	duplicate_str = strdup(str);
	if (!duplicate_str)
		return (NULL);

	while (duplicate_str[len])
		len++;

	new_node = malloc(sizeof(list_t));
	if (!new_node)
	{
		free(duplicate_str);
		return (NULL);
	}

	new_node->str = duplicate_str;
	new_node->len = len;
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}

	return (new_node);
}
