#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define ALPHAB 26

void print_words_alphabetically(char ***alphabetical_array)
{
    int row, col;

    /*for loop to print words from alphabetical_array*/
    for (row = 0; row < ALPHAB; row++) {
        col = 0;

        /*using ASCII value of 'A' and value of row to print letters in ascending order*/
        printf("'%c'\n", row + 'A');
        /*printing each string in the row of the 3d array*/
        while (alphabetical_array[row][col] != NULL) {
            printf("%s\n", alphabetical_array[row][col]);
            col++;
        }

        /*checking if there are no words associated with the respective letter*/
        if (col == 0) {
            printf("There are no words that begin with the letter '%c'\n", row + 'A');
        }
        printf("\n");
    }
}