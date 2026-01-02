/*
Celsius to Fahrenheit

 Purpose: Print two columns on the screen with the temperature in 
		degrees Celsius and the equivalent temperature in degrees Fahrenheit, using a while loop.

Ruochen Bao
*/

#include <stdio.h>

int main()
{
    float start_celsius = 0; // start of celsius column
    float end_celsius = 19;  // end of celsius column
    float step_celsius = 1; // step size from start to end of celsius column
    float fahrenheit, celsius;

    celsius = start_celsius;
    printf("Celsius\t\tFahrenheit\n"); //print header

    while (celsius<=end_celsius)
    {
        fahrenheit = (9 * celsius + 160) / 5; // calculate fahrenheit
        printf("%10.1f\t%10.1f\n", celsius, fahrenheit);
        celsius += step_celsius;
    }
    return 0;
}