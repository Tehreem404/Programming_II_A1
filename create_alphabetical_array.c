#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define MAX_LETTERS 46
#define ALPHAB 26

char ***create_alphabetical_array(char **word_list, int count[])
{
    int i = 0;
    int letter;
    int end;
    int column;
    int j;
    int count_copy[ALPHAB];
    /*initiating 3d array*/
    char ***alphabetical_array = malloc (ALPHAB*sizeof(char **));
    
    /*for loop that adds a NULL pointer to the end of each row of strings in the 3d array*/
    for (letter = 0; letter < ALPHAB; letter++) {
        /*making a copy of count to prevent memory issues in int main*/
        count_copy[letter] = count[letter];
        /*getting the end location of the row of strings using count*/
        end = count[letter];
        alphabetical_array[letter] = malloc(sizeof(char *) * end);

        /*getting to the end location of the row*/
        for (j = 0; j < end; j++){
            alphabetical_array[letter][j] = malloc (sizeof(char) * MAX_LETTERS);
        }
        /*adding NULL pointer when end is reached*/
        alphabetical_array[letter][end] = NULL;
    }

    /*while loop that makes the alphabetical array*/
    while (word_list[i] != NULL){
        /*organsing lowercase letters*/
        if (word_list[i][0] >= 'a' && word_list[i][0] <= 'z'){
            letter = word_list[i][0] - 'a';
            
            /*using count_copy to go backwards within the 3d array space [row] when a letter in the respective count is found*/
            /*column is overwritten each time to go down the row*/
            column = count_copy[letter] - 1;
            count_copy[letter] = count_copy[letter] - 1;

            strcpy(alphabetical_array[letter][column], word_list[i]);
        }
        /*organising uppercase letters*/
        if (word_list[i][0] >= 'A' && word_list[i][0] <= 'Z'){
            letter = word_list[i][0] - 'A';

            /*using count_copy to go backwards within the 3d array space [row] when a letter in the respective count is found*/
            /*column is overwritten each time to go down the row*/
            column = count_copy[letter] - 1;
            count_copy[letter] = count_copy[letter] - 1;

            strcpy(alphabetical_array[letter][column], word_list[i]);        
        }
        /*almost combines read_words and alphabetical_word_count to make alphabetical_array*/
        i++;
    }
    return(alphabetical_array);
}