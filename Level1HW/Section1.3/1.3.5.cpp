/*
This program shows the difference between --i and i--:
    --i: pre-decrement
    i--: post-decrement

Ruochen Bao
*/

#include <stdio.h>

int main()
{
    int i = 0; // initialised an integer
    printf("initialised i: %d\n", i);

    int a = --i; // pre-decrement, i = -1, a = -1
    printf("a = --i =  %d, %d\n", a, i);

    int b = i--; // post-decrement, b = i = -1, i = -2, 
    printf("b = i-- =  %d\n", b);
    printf("i = %d\n", i);
    return 0;
}