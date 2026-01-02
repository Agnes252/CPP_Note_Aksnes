/*
    Read the characters from the keyboard.
    When ^A (ASCII value = 1) is entered, end with printing "CTRL + A is a correct ending."
    Inputted characters should only be written to the file when the user hits 'enter'

    Modifications:
    2025.3.16 Simplify as 1.9.1sim.cpp;
        filename is specified by the user

    2025.3.14
    Ruochen Bao
*/

#include <stdio.h>

int main()
{
    FILE* fp;
    int input_char = 0; // a character inputted
    char filename[100]; // filename "xxx.txt"

    // get user specified file name
    printf("Please specify the file name to write: ");
    scanf("%s", filename);

    fp = fopen(filename, "w"); // open/create the file to write

    if (fp == NULL) 
    {
        printf("Error: Unable to open file!\n");
        return 1; // Exit
    }

    printf("Please start printing. End with CTRL+A.\n");


    // before CTRL+A is inputted
    while ((input_char = getchar()) != 1) 
    {
        if (input_char != '\n') 
        {
            fputc(input_char, fp);  // print each character as it is inputted
        }
        else 
        {
            fputs("\n", fp); // print newline when enter is pressed
        }
    }
}
