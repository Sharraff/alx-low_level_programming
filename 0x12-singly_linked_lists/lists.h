#ifndef _LIST_H
#define _LIST_H
#include <stdlib.h>

/**
 *list_t - structure containing elements of node of the linked list
 *@str: field for string
 *@len: lenght of the string
 *@next: pointer to the next node in the list
 *
 *
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;



size_t print_list(const list_t *h);
size_t list_len(const list_t *h);

#endif /*LIST_H*/
