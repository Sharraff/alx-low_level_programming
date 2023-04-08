#include <stdio.h>

char *stringcon(char *s1, char *s2)
{
	int i = 0;
	int len1 = 0;
	


	while (s1[len1] != '\0')
		len2++;


	for (i = 0; s1[i] != '\0'; i++)
	{
		s1[len1 + i] = s2[i];
	}
	s1[len1 + i] = '\0';

	return (s1);
}


int main()
{
	
	char *con;

	con = stringcon("man", "woman");
	printf("%s\n", con);

	return (0);
}
