#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 success
 */
int main(void)
{
	int count = 2;
	long int i = 1;
	long int j = 2;
	long int k;

	printf("%ld, ", i);
	while (count <= 50)
	{
		if (count == 50)
		{
			printf("%ld\n", j);
		}
		else
		{
			printf("%ld, ", j);
		}
		k = j;
		j += i;
		i = k;
		count++;
	}
	return (0);
}
