#include "main.h"

/**
 * largest_number - returns the largest of 3 numbers
 * @a: - first integer
 * @b: - second integer
 * @c: - third integer
 * Return: 0 Always success
 */

int largest_number(int a, int b, int c)
{
	int largest = a;

	if (largest < b)
	{
		largest = b;
		if (largest < c)
			largest = c;

	{
}
