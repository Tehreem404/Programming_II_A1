#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LETTERS 46
#define ALPHAB 26

int file_size(FILE *fp)
{   
    /*calculating file size in bytes*/
    int sz = 0;
    fseek(fp, 0L, SEEK_END);
    sz = ftell(fp);
    rewind(fp);
    return(sz);
}

char **read_words(FILE *fp)
{   
    /*max_words is the approximate projection of the ammount of words in the 2d array*/
    int max_words = ((file_size(fp)/2) + 1);
    int i = 0;
    char **two_dimensional_array;
    char word[MAX_LETTERS + 1];

    two_dimensional_array = malloc(sizeof(char *) * (max_words));
    
    /*[scanf method] making a dynamic array (2d)*/
    while (fscanf (fp, "%s", word) != EOF){
        two_dimensional_array[i] = malloc(sizeof(char) * MAX_LETTERS);
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

char ***create_alphabetical_array(char **word_list, int count[])
{
    int i = 0;
    int letter;
    int end;
    int column;
    int j;
    int count_copy[26];
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
            alphabetical_array[letter][j] = malloc (sizeof(char) * 45);
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

void free_alphabetical_array(char ***alphabetical_array)
{

}

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

int main (int argc, char *argv[])
{
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

        print_words_alphabetically(alphabetical_array);

    }
    return(0);
}