/*
Fahrenheit to Celsius

 Purpose: Print two columns on the screen with the temperature in 
		degrees Fahrenheit and the equivalent temperature in degrees Celsius, using a while loop.

 Ruochen Bao
*/

#include <stdio.h>

int main()
{
    float start_fahrenheit = 0; // start of fahrenheit column
    float end_fahrenheit = 300; // end of fahrenheit column
    float step_fahrenheit = 20; // step size from start to end of fahrenheit column
    float fahrenheit, celsius;

    fahrenheit = start_fahrenheit;
    printf("Fahrenheit\tCelsius\n"); //print header

    while (fahrenheit<=end_fahrenheit)
    {
        celsius = 5 * (fahrenheit - 32) / 9; // calculate celsius
        printf("%10.1f\t%10.1f\n", fahrenheit, celsius);
        fahrenheit += step_fahrenheit;
    }
    return 0;
}