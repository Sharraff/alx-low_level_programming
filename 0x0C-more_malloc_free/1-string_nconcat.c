#include <stdio.h>
#include <stdlib.h>

/**
 * string_nconcat - function that concatenates two strings
 * @s1: first string
 * @s2: second string to concatenate with s1
 * @n: n amout of bytes
 * Return: pointer to concatenated string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0;
	char *temp;
	unsigned int len1 = 0;
	unsigned int len2 = 0;

	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL)
		return (NULL);

	if (n >= len2)
		n = len2;
	temp = malloc(sizeof(char) * n + len1 + 1);

	for (i = 0; i < len1; i++)
	{
		temp[i] = s1[i];
	}
	for (i = 0; i < n; i++)
	{
		temp[i + len1] = s2[i];
	}
	temp[i + len1] = '\0';

	return (temp);
}
