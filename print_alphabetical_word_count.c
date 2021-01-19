#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define ALPHAB 26

void print_alphabetical_word_count(int count[])
{ 
    int i = 0;

    /*for loop counting for each letter in the alphabet*/
    for (i = 0; i < ALPHAB; i++){
        /*printing the letter based on ASCII value of 'A' and integer value of i*/
        printf("%c:  ", i + 'A');
        /*printing the count based on the respective letter*/
        printf("%d\n", count[i]);
    }
    printf("\n");
}