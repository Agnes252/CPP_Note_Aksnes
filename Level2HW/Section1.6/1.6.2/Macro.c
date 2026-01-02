/*
	Defs.h contains two macro calls: MAX2, MAX3
	MAX2 get max(arg1, arg2), and macro MAX3 make use of the macro MAX2

	2025.3.14
	Ruochen Bao
*/

#include <stdio.h>
#include "Defs.h"

int main()
{
	double a, b, c, result;

	// Ask the user to input a and b.
	printf("Please input 2 or 3 numbers using the following format:\na b c\n");

	if (scanf_s("%lf %lf %lf", &a, &b, &c))
	{
		result = MAX2(a, b);
		PRINT(result); // print the max of a,b

		result = MAX3(a,b,c);
		PRINT(result); // print the max of a,b,c
	}

	else
	{
		printf("Input Error.\n");
	}	

	return 0;
}