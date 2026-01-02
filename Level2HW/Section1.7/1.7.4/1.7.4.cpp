/*
    Input a daynumber (1 to 7), and print the weekday. 

    Revised: 2025.3.16 Uses a DayName function.
        Simplify the char *dayNames[] = {"Sunday",".."}
 
    2025.3.14
    Ruochen Bao
*/


#include <stdio.h>
#include <string.h>

int DayName(int daynumber)
{
    char* day;
    char* dayNames[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    
    day = dayNames[daynumber-1]; // get the content indexed with (daynumber - 1), since array starts with index 0
    printf("%d gives: Day %d is a %s", daynumber, daynumber, day);

    return 0;
}




int main()
{
    int daynumber; // daynumber input

    // receive daynumber input
    printf("Please input a daynumber (1,2,3,4,5,6, or 7) \n");

    if (scanf_s("%d", &daynumber)) // get the legal input: daynumber
    {
        DayName(daynumber);
    }
    else
    {
        printf("Input error."); // illegal input error
        return 1;
    }
}




