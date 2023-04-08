#include <stdio.h>
#include <stdlib.h>

char *strconcat(char *str1, char *str2);

int main()
{
	char *concat;

	concat = strconcat("boys", "girls");
	printf("%s\n", concat);
	
	return (0);
}


char *strconcat(char *str1, char *str2)
{
	int i = 0;
	char *temp;
	int len1 = 0;
	int len2 = 0;
	int n = 0;
	int j, k, l = 0;


	if (str1 == NULL)
		return (NULL);
	if (str2 == NULL)
		return (NULL);
	for (k = 0; str1[len1] != '\0'; k++)
		len1++;
	for (l = 0; str2[len2] != '\0'; l++)
		len2++;
	n = len1 + len2;
	
	temp = malloc(sizeof(char) * n + 1);
	for (i = 0; i < len1; i++)
		temp[i] = str1[i];
	for (j = 0; j < len2; j++)
		temp[j + len1] = str2[j];
	temp[i + len1] = '\0';


	return (temp);
}
