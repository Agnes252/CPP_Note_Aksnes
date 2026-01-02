/*
The variable called married: takes 0 or non-zero, 
0 (zero) is interpreted as "not married" and non-zero is interpreted as "married"

Ruochen Bao
*/

#include <stdio.h>

int main()
{
    int married = 0; // Can set "married" to be 0 or non-zero here.
    bool isMarried = (married == 0) ? false : true;
    printf("Married: %s\n", isMarried ? "True" : "False"); // use only 1 printf()
}