/*
	Defs.h contains two print macro calls: PRINT1, PRINT2

	2025.3.14
	Ruochen Bao
*/


#include <stdio.h>
#include "Defs.h"

int main()
{
	double a, b;

	// Ask the user to input a and b.
	printf("Please input two numbers using the following format:\na b\n");

	if (scanf_s("%lf %lf", &a, &b))
	{
		// Print variable a.
		PRINT1(a);

		// Print variable a and b.
		PRINT2(a, b);
	}
	else
	{
		printf("Input Error.\n");
	}	
}