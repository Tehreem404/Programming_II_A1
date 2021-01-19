#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define ALPHAB 26

int *alphabetical_word_count(char **two_dimensional_array)
{
    /*https://www.programmingsimplified.com/c-program-find-characters-frequency
    was referenced to create alphabetical_word_count*/

    int i = 0;
    int x;
    int *count = malloc(sizeof(int) * (ALPHAB));
    
    while (two_dimensional_array[i] != NULL){
        /*counting for lowercase letters*/
        if (two_dimensional_array[i][0] >= 'a' && two_dimensional_array[i][0] <= 'z'){
            /*x represents the location of the number count refrencing to its letter*/
            x = two_dimensional_array[i][0] - 'a';
            /*adding to the count in its respective letter location*/
            count[x]++;
        }
        /*counting for uppercase letters*/
        if (two_dimensional_array[i][0] >= 'A' && two_dimensional_array[i][0] <= 'Z'){
            /*x represents the location of the number count refrencing to its letter*/
            x = two_dimensional_array[i][0] - 'A';
            /*adding to the count in its respective letter location*/
            count[x]++;
        }
        i++;
    }
    return (count);    
}