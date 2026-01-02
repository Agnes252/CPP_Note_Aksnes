/*
This program multiplies a number by a factor 2 to the power n using shifts.

Ruochen Bao

Revision: 2025.3.14, the loop simplified.
*/

#include <stdio.h>

int main() 
{
    int i= 3, n = 5; // multiply i by 2**n

    printf("i initialised to: %d\n", i);

    /*
    for (int k = 1; k <= n; k++)
    {
        i = i << 1; // equals to i *= 2
        printf("i*(2**%d) evaluates to: %d\n", k, i);
    }
    */

    i = i << n; // evaluates to number*2^N
    printf("i*(2**%d) evaluates to: %d\n", n, i);
    
    return 0;
    
}