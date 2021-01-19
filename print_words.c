#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

void print_words(char **two_dimensional_array)
{   
    int i = 0;

    /*checking for empty text file*/
    if (two_dimensional_array[0] == NULL){
        printf("There are no words in the text file\n");
        exit(1);
    }

    /*printing each word in the dynamic array*/
    while (two_dimensional_array[i] != NULL){
        printf("%s\n", two_dimensional_array[i]);
        i++;
    }
    printf("\n");
}