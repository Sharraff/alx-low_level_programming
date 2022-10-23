#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 *list_len - this function counts the number of elements in a list.
 *
 *@h: pointer to next element of node
 *Return: return count.
 */
size_t list_len(const list_t *h)
{
	char *str;
	unsigned int len;
	int i = 0;
	unsigned int count = 0;


	for (i = 0; h != NULL; i++)
	{
		if (str == NULL)
			printf("(nill)");
		h = h->next;
		count++;
	}
	return (count);
}
