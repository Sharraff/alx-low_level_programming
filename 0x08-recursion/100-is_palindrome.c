#include "main.h"
/**
 * is_palindrome - returns 1 if a string is a palindrome and 0 if not
 *
 * @s: string
 * Return: int
 */
int is_palindrome(char *s)
{
	int len = _strlen_recursion(s);
	int i = 0;

	if (len == 0)
		return (1);
	return (palindrome_check(s));
	return (palindrome_check(len - 1));
	return (palindrome_check(i));
}

/**
 * _strlen_recursion - returns the length of a string
 *
 * @s: string
 * Return: int
 */
int _strlen_recursion(char *s)
{
	int len;

	if (*s == '\0')
	{
		return (0);
	}
	len = _strlen_recursion(s + 1);
	return (len + 1);
}

/**
 *  * palindrome_check - returns 1 if palindrome and 0 if not
 *
 * @s: string
 * @len: length of string
 * @i: counter variable
 * Return: int
 */
int palindrome_check(char *s, int len, int i)
{
	if (len == i)
	{
		return (1);
	}
	else if
		return (0);
	if (i < len)
		return (palindrome_check(s, --len, ++i));
	return (1);
}
