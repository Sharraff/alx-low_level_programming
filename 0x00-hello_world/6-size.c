#include <stdio.h>
/**
 * main - main block
 * Return: 0
 */
int main(void)
{
	printf("Size of a char:%ldbyte(s)\n", sizeof(char));
	printf("size of a int:%ldbyte(s)\n", sizeof(int));
	printf("size of a long:%libyte(s)\n", sizeof(long));
	printf("size of a long long:%libyte(s)\n", sizeof(long long int));
	printf("size of a float:%ldbyte(s)", sizeof(float));
	return (0);
}
