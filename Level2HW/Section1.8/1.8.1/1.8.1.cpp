/*
    Print the contents of a struct called Article.
    Printing is done by a Print() function.

    Fields in Article: article number, quantity, description(20 chars)

    Modifications:
    2025.3.16. Initialising struct Article ar. strcpy is runtime.

    2025.3.14
    Ruochen Bao
*/


#include <stdio.h>
#include <string.h>

#ifndef LENGTH
#define LENGTH 20 // define the maximum length of description
#endif

struct Article // define a struct called Article 
{
    unsigned int article_number; 
    unsigned int quantity;
    char description[LENGTH];
};

void Print(struct Article* pt) // print fields
{
    printf("Article number: %u\n", (pt)->article_number);
    printf("Quantity: %u\n", (pt)->quantity);
    printf("Description: %s\n", (pt)->description);
}

int main()
{
    struct Article article = {10,7,"description"}; // initialising
    struct Article* article_pt; // pointer of the struct

    article_pt = &article; // assign the address to the pointer

    Print(article_pt); // pass the pointer to the printing function
}

