#include "main.h"
/**
 * string_toupper - function to transform all lowercase in string to uppercase
 *
 * @s: character string pointer
 * Return: char pointer
 */
char *string_toupper(char *s)
{
	char *start = s;

	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s -= 32;
		s++;
	}
	return (start);
}
