#include <stdio.h>
#include "Multiply.h"

int main()
{
	double i;

	printf("Please input a number.\n"); // Ask the user tp input a number.

	if (scanf("%lf", &i))
	{
		// If the user input a number, call print() to multiplies i by 2 and print it.
		print(i);
	}
	else
	{
		// If the user fails to input a number, send error message and exit.
		printf("Input Error.");
	}
}
