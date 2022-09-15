#include "main.h"
/**
 * _islower - this function checks for lowercase characters
 *
 * Return: Always 0
 *
 *@c: character to compare
 */
int _islower(int c)
{
	if (c >= 97 && c <= 123)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
