/*
Calculate the surface of a triangle with one 90 degree angle.

Ruochen Bao
*/

#include <stdio.h>

int main()
{
	double base = 3, height = 4; // set the base and height of the triangle
    double surface;

    surface = base * height / 2; // compute the surface
    printf("The surface is %lf\n", surface);
}