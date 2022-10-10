#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	struct dog my_dog;

	my_dog.name = "poppy";
	my_dog.age = 3.5;
	printf("My name is %s, and i am %.1f :) - Woof!\n", my_dog.name, my_dog.age);
return (0);
}

