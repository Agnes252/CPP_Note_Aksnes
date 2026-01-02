/*
Build a recursive function which uses putchar() to print an integer by digits.

Ruochen Bao

Revised on 2025/3/14: Negative number handling should be self-contained in the printnumber function.
*/

#include <stdio.h>

// recursive function
void printnumber(int n) 
{
    if (n < 0) // turn negative numbers into positive numbers
    {
        putchar('-'); 
        n = -n; 
    }
    if (n == 0)  // directly print '0'
    {
        putchar('0');
    } 
    else 
    {
        if (n >= 10) 
        {
            printnumber(n / 10);
        }
        putchar(n % 10 + '0'); // turn into number output
    }
    
}

int main() 
{
    int n;
    printf("Please input a number: \n");
    scanf("%d", &n);

    printnumber(n);

    putchar('\n');
    return 0;
}
