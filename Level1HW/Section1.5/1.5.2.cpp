/*
 function: factorials of input n. 
 
 Receive n as input, and retuns n!.

 Revised on 2025/3/14: 
 Input argument type should be unsigned int.
 Return type should be long long.

 Ruochen Bao
*/

#include <algorithm>
#include <stdio.h>

// Recursive function: compute n!
long double factorial(int n) 
{ 

        if(n == 0)
		{
			return 1;
		}

		return n * factorial(n-1);
}


int main()
{ 
    unsigned int N = 6; // to compute N!

	printf("%u! = %.0Lf\n", N, factorial(N));

    return 0;
}


