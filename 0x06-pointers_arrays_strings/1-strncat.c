#include "main.h"
/**
* _strncat - function to concatenate two strings and return a new string
* with n elements of the appended string
* @dest: string 1
* @src: string 2
* @n: number of chars to include from appended string
* Return: char pointer
*/
char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	for (j = 0; dest[j] != '\0'; j++)
	{}

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[j + i] = src[i];
	}
	dest[j + i] = '\0';

	return (dest);
}
