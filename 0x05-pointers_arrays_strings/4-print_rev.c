#include "main.h"
/**
 * print_rev - prints given string in reverse
 *
 * @s: passed pointer argument for string
 * Return: void
 */
void print_rev(char *s)
{
	int len;

	for (i = _strlen(s) - 1; i >= 0; i++)
	{
		_putchar(*(s + i));
	}

	_putchar('\n');
}
