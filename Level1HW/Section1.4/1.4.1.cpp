/*
 A program that reads text from the keyboard, and reports the number of characters, words, and lines in the text. 

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
	bool flg_last_character = false; // set to true when last input is a character; false when not
	bool flg_last_new_line = false; // set to true when last input is a new line; false when not

	printf("Please input text, using Ctrl+D to stop.\n");

	while ((ASCII_input_character = getchar()) != 4)  // If input is ^D (ASCII-value = 4), jump out of the loop
	{

		if (ASCII_input_character == 32 || ASCII_input_character == 9) // If pressing space or tab
		{
			if (flg_last_character)
			{
				num_words++; // If last input is a character, count as a new word
			}

			if (flg_last_new_line)
			{
				num_newlines++; // If last input is a new line, count as a new line
			}

			flg_last_character = false;
			flg_last_new_line = false;
		}
		else if (ASCII_input_character == 10) // If starting a new line(ASCII-value = 10)
		{
			if (flg_last_character)
			{
				num_words++; // If last input is a character, count as a new word.
			}

			if (flg_last_new_line)
			{
				num_newlines++; // Consecutive new lines should count as multiple new lines.
			}

			flg_last_character = false; // without this line, multiple spaces input at the start of a new line will be miscounted as a word
			flg_last_new_line = true;
		}		
		else
		{
			num_characters++;
			if (flg_last_new_line)
			{
				num_newlines++; // If last input is a new line and current input is a character, count as a new line.
				flg_last_new_line = false;
			}

			flg_last_character = true;
		}
	}

	if (flg_last_character) // At the end of the text, if last input is a character, the current word should be counted as a new word.
	{
		num_words++;
	}

	if ((num_words > 0) && (ASCII_input_character != 10))
	{
		num_newlines++; // the last line is counted
	}

	printf("The amount of characters is %d.\nThe amount of words is %d.\nThe amount of new lines is %d.\n",
		num_characters, num_words, num_newlines);
}