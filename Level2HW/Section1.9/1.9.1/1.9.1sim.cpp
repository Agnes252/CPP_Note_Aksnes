/*
    Read the characters from the keyboard, then show them on screen.
    When ^A (ASCII value = 1) is entered, end with printing "CTRL + A is a correct ending."
    Inputted characters should only be displayed when the user hits 'enter'

    2025.3.14
    Ruochen Bao
*/

#include <stdio.h>


int main()
{
    int input_char = 0; // a character inputted

    printf("Please start printing. End with CTRL+A.\n");

    while ((input_char = getchar()) != 1) 
    {
        if (input_char != '\n') 
        {
            putchar(input_char); // print each character as it is inputted
        }
        else 
        {
            putchar('\n'); // print newline when enter is pressed
        }
    }

    printf("CTRL + A is a correct ending.\n"); 
    return 0;
}
