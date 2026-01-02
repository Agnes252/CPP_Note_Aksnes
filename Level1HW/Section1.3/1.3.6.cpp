/*
This program shifts any number 2 places to the right.
Input should be an integer.
Output are the shifted number and an indication of whether a logical or arithmetic shift is performed.

Ruochen Bao
*/

#include <stdio.h>

int main() 
{
    int i; 
    i = -3; // integer input
    printf("i=%d\n", i);

    i = i >> 2; // shifts the number 2 places to the right
    printf("i >> 2 evaluates to: %d\n" , i);

    printf("An arithmetic shift is performed.\n"); // i is a signed integer, so an arithmetic shift is performed.
}