#include "3-calc.h"

/**
 * main - performs simple operations
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: int
 */
int main(int argc, char *argv[])
{
	int a;
	int b;
	int res;

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}
	a = atoi(arg[i]);
	b = atoi(arg[3]);
	if (!get_op_func(arg[2]) || arg[2][1] != '\0')
	{
		printf("Error\n");
		return (99);
	}
	if (b == 0 && (*arg[2] == '/' || *arg[2] == '%'))
	{
		printf("Error\n");
		return (100);
	}
	res = get_op_func(arg[2])(a, b);
	printf("%d\n", res);
	return (0);
}
