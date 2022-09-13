#include "main.h"
#include <stdlib.h>
/**
 * print_alphabet - prints alphabet
 *
 * Return:Always retun 0 on successful execution
 */
void print_alphabet(void)
{
	char i = 0;


	for (i = 'a'; i <= 'z'; i++)
	{
		_putchar(i);
	}
	_putchar('\n');
}
