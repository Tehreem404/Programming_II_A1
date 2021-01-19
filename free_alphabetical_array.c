#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define MAX_LETTERS 46
#define ALPHAB 26

void free_alphabetical_array(char ***alphabetical_array)
{
  /*https://stackoverflow.com/questions/17820018/free-dynamically-created-3d-array-in-c/17822560#17822560
  was refrenced to make this function*/

  int i, j;

  for(i = 0; i < ALPHAB; i++){
    for (j = 0; j < MAX_LETTERS; j++){
      free(alphabetical_array[i][j]);
    }
    free(alphabetical_array[i]);
  }
  free(alphabetical_array);
}