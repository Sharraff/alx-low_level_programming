#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 *
 *
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
