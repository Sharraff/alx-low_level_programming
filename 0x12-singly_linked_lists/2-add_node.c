#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * add_node - A function that adds a node to the head of linked list
 *
 * @head: pointer to a list_t pointer that points to the head struct
 * @str: pointer to string that adds as node
 * Return: pointer to new head of list, NULL on failure
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *node;
	int lenght = 0;

	while (str[lenght])
		lenght++;

	node = malloc(sizeof(list_t));
	if (node == NULL)
	{
		return (NULL);
	}


	node->len = lenght;
	node->str = strdup(str);
	node->next = *head;
	*head = node;

	return (node);
}
