/*
 function: minus.
 
 Receive a,n as input, and retuns the difference (a-b).

 Ruochen Bao
*/

#include <stdio.h>

// function：compute (a-b)
float minus(float a, float b)
{
    return a-b;
}

int main()
{
    float result;
    float a = 5.0, b = 3.0;
    printf("The result is: %.2f\n", minus(a,b));
    return 0;
}


