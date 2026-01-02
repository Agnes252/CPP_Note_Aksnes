/*
 A program that reads text from the keyboard, and reports the number of characters, words, and lines in the text. 
 Using "do-while" instead of while(see 1.4.1.cpp).

 Notice: A word is defined as any sequence of characters separated by spaces. 
 Assume that the input ends with an end-of-file indicator (Ctrl+D on the keyboard).

 Ruochen Bao
*/


#include <stdio.h>

int main()
{
	int ASCII_input_character = NULL; // ASCII-value of the input
	int num_characters = 0; // number of characters input
	int num_words = 0; // number of words input
	int num_newlines = 0; // number of new lines input
	bool flg_last_character = false; // set to true when last input is a character, but false when not
	bool flg_last_new_line = false; // set to true when last input is a new line, but false when not

	printf("Please input text, using Ctrl+D to stop.\n");

	while ((ASCII_input_character = getchar()) != 4) // If input is ^D(ASCII-value = 4), jump out of the loop.
	{
        switch (ASCII_input_character)
        {
            case 32: // If pressing space
            case 9: // If pressing tab
                switch (flg_last_character) 
                { 
                    case 1: num_words++; break; // If last input is a character, count as a new word.
                    case 0: break;
                } 

                switch (flg_last_new_line) 
                { 
                    case 1: num_newlines++; break; // If last input is a new line, count as a new line
                    case 0: break;
                } 

                flg_last_character = false;
                flg_last_new_line = false;
            break;
            
            case 10: // if pressing new line(ASCII-value = 10)
                switch (flg_last_character)
                {
                    case 1: num_words++; break; // If last input is a character, count as a new word.
                    case 0: break;
                }

                switch (flg_last_new_line)
                {
                    case 1: num_newlines++; break; // Consecutive new lines should count as multiple new lines.
                    case 0: break;
                }

                flg_last_character = false;
                flg_last_new_line = true;
            break;

            default:
                num_characters++;
                switch (flg_last_new_line)
                {
                    case 1:
                        // If last input is a new line and current input is a character, count as a new line.
                        num_newlines++;
                        flg_last_new_line = false;
                        break;
                    default:
                        break;
                }
                flg_last_character = true;
            break;
        }		
    }

    // At the end of the text, if last input is a character, the current word should be counted as a new word.
	switch (flg_last_character)
    {
        case 1: num_words++; break;
        case 0: break;
    }

    switch (num_words)
    {
        case 0: break;
        default: 
        {
            switch (ASCII_input_character)
            {
                case 10: break;
                default: num_newlines++;
            }
        }
        
    }
	
	printf("The amount of characters is %d.\nThe amount of words is %d.\nThe amount of new lines is %d.\n",
		num_characters, num_words, num_newlines);
}