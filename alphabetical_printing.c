#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define MAX_LETTERS 46
#define ALPHAB 26

int main (int argc, char *argv[])
{
    int file_size(FILE *fp);
    char **read_words(FILE *fp);
    void print_words(char **two_dimensional_array);
    int *alphabetical_word_count(char **two_dimensional_array);
    void print_alphabetical_word_count(int count[]);
    char ***create_alphabetical_array(char **word_list, int count[]);
    void print_words_alphabetically(char ***alphabetical_array);
    void free_alphabetical_array(char ***alphabetical_array);
    
    FILE *fp;
    fp = fopen(argv[1], "r");

    if ((fp = fopen(argv[1], "r")) == NULL){
        printf ("File chosen was not found\n");
        printf ("Usage: ./alphabetical_printing <filename.txt>\n");
        exit(2);
    }

    char **two_dimensional_array = read_words(fp);

    print_words(two_dimensional_array);

    int *count = alphabetical_word_count(two_dimensional_array);

    print_alphabetical_word_count(count);

    char ***alphabetical_array = create_alphabetical_array(two_dimensional_array, count);

    /*free_alphabetical_array(alphabetical_array);*/

    print_words_alphabetically(alphabetical_array);

    /*opening a second text file*/
    if (argc == 3){
        FILE *fp;
        fp = fopen(argv[2], "r");

        char **two_dimensional_array = read_words(fp);

        print_words(two_dimensional_array);

        int *count = alphabetical_word_count(two_dimensional_array);

        print_alphabetical_word_count(count);

        char ***alphabetical_array = create_alphabetical_array(two_dimensional_array, count);

        /*free_alphabetical_array(alphabetical_array);*/

        print_words_alphabetically(alphabetical_array);

    }
    return(0);
}
