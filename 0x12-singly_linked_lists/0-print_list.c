#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"
/**
 *print_list - prints a list
 *@h: head of list
 *Return: number of elements
 */
size_t print_list(const list_t *h)
{
	list_t *h;
	size_t nodes = 0;


	while (h != NULL)
	{
		if (h->str == NULL)
			printf("(nil"\n);
		else
			printf("%s,%u", h->str, h->len);
		h = h->next;
		nodes++;

	}
	return (node);
}
