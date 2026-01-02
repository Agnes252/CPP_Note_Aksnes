/*
    Read the characters from the keyboard, then show them on screen.
    When ^A (ASCII value = 1) is entered, end with printing "CTRL + A is a correct ending."
    Inputted characters should only be displayed when the user hits 'enter'

    2025.3.14
    Ruochen Bao
*/

#include <stdio.h>

#ifndef MAX_LENGTH
#define MAX_LENGTH 20 // Maximum characters per line. For testing, it is set to 20 here.
#endif

int main()
{
    int input_char = 0; // a character inputted
    char output_line[MAX_LENGTH]; // the string to store inputted characters each line
    int input_count = 0; // count the inputted characters per line

    printf("Please start printing. End with CTRL+A.\n");

    // before CTRL+A is inputted
    while ((input_char = getchar()) != 1) 
    {
        if (input_count < MAX_LENGTH - 1) // Assure that inputted characters < MAX_LENGTH
        {
            if (input_char != 10) 
            {
                output_line[input_count++] = input_char; // before '\n' is inputted, store the input
            }

            else // print the line when '\n' is inputted
            {
                output_line[input_count] = '\0'; // End the output line

                for (int i = 0; i < input_count; i++)
                {
                    putchar(output_line[i]); // print the last line (character by character) 
                }

                putchar('\n');
                input_count = 0; // initialised input counts per line to 0
            }
        }

        else // Inputted characters this line exceeding MAX_LENGTH
        {
            printf("Inputted characters exceeding maximum chars per line:%d", MAX_LENGTH);
            return 1; // Exit
        }
    }
    
    // If the last inputted line ends with CTRL+A, print the last line before printing "correct ending"
    if (input_count > 0) 
    {
        for (int i = 0; i < input_count; i++)
            {
                putchar(output_line[i]); // print the last line (character by character) 
            }
    }

    printf("CTRL + A is a correct ending."); 
    return 0;
}
