/*
    Swap(): exchange the value of two variables
    It receives two pointers as arguments.

    2025/3/14 Ruochen Bao
*/

#include <stdio.h>

// swaps values of two numbers (type: double)
void Swap(double* a, double* b)
{
    double a_value;
    a_value = (*a); // copy the value stored in a
    (*a) = (*b); // assign b to a 
    (*b) = a_value; // contents of the address b changed to a_value
}

int main()
{
    double i, j; // inputs; numbers to be swapped
    printf("Please input 2 numbers using the following format:\na b\n");

    if (scanf_s("%lf %lf", &i, &j)) // get the legal input, two numbers (type: double)
    {
        Swap(&i, &j); // swap values of legal input, using address as arguments
        printf("Swapped: %lf, %lf", i, j);
    }
    else{
        printf("Input error.");
    }

    return 0;
}