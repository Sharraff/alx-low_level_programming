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
	unsigned int nodes = 0;


	while (h)
	{
		if (h->str == NULL)
			printf("(nil"\n);
		else
			printf("%s,[%u] ", h->str, h->len);
		h = h->next;
		nodes++;

	}
	return (nodes);
}
