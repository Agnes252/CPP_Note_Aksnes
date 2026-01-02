/*
 Count how many times each of the numbers 0-4 have been typed. 

 Note: Use a switch-case construction. Use default to count the number of other characters. 
 The input will be halted with ^Z (EOF). The output of printf is changed. 

 Ruochen Bao
*/

#include <stdio.h>

int main()
{
    char input_character = NULL; 
    int n_0, n_1 = 0, n_2 = 0, n_3 = 0, n_4 = 0; //initialised times of number 0-4
    int n_other = 0; //initialised times of other characters
    
    printf("Please input text, using Ctrl+Z(or EOF) to stop.\n");

    while ((input_character = getchar()) != EOF)
    {
        switch (input_character)
        {
            case '0':
                n_0++;
                break;
            case '1':
                n_1++;
                break;
            case '2':
                n_2++;
                break;
            case '3':
                n_3++;
                break;
            case '4':
                n_4++;
                break;
            default:
                n_other++;
                break;
        }
    }
    
    // print results
    printf("Number of 0s: %d\n", n_0);
    printf("Number of 1s: %d\n", n_1);
    printf("Number of 2s: %d\n", n_2);  
    printf("Number of 3s: %d\n", n_3);
    printf("Number of 4s: %d\n", n_4);
    

    switch (n_3) // print times of 3 in words.
	{
		case 0:
			printf("Number three appears zero time.\n");
			break;
		case 1:
			printf("Number three appears one time.\n");
			break;
		case 2:
			printf("Number three appears two times.\n");
			break;
		default:
			printf("The number three appears more than two times.\n");
			break;
	}

    return 0;
}