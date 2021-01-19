#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

char **read_words(FILE *fp)
{   
    int file_size(FILE *fp);

    /*max_words is the approximate projection of the ammount of words in the 2d array*/
    int max_words = ((file_size(fp)/2) + 1);
    int i = 0;
    char **two_dimensional_array;
    char word[46];

    two_dimensional_array = malloc(sizeof(char *) * (max_words));
    
    /*[scanf method] making a dynamic array (2d)*/
    while (fscanf (fp, "%s", word) != EOF){
        two_dimensional_array[i] = malloc(sizeof(char) * 45);
        strcpy(two_dimensional_array[i], word); 
        i++;
    }
    /*scanf will get rid of '\n' and any empty lines*/

    /* [fgets method] (not used) making a dynamic array (2d) (NEED CHOP FUNCTION TO REMOVE '\n')
    char string[size];
    char *word;
    int size = file_size(fp);

    while (fgets (string, size, fp) != NULL){
        word = strtok(chop(string), " ");

        while (word != NULL){
            cptr[i] = malloc(sizeof(char) * 45);
            strcpy(cptr[i], word); 
        
            word = strtok(NULL, " ");
            printf("%s\n", cptr[i]);

            i++;
        }
    }*/

    /*adding a NULL pointer to the end of the dynamic array*/
    two_dimensional_array[i] = NULL;
    return (two_dimensional_array);
}