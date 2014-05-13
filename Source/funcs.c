/*****
 *  Solution to examination project in High Performance Computing and Programming
 * 
 *  funcs.c functions implementation file
 *
 * Author: Marcus Holm
 *
 **/

#include "common.h"
#include "funcs.h"


void create_random_array(star_t * stars, int size)
{
  
}

void print_stars(star_t* array, int n)
{
   int i;
   for(i = 0; i<n; i++)
      printf("%s ",array[i].designation);
   printf("\n");
}




void sort(star_t* array, int n) 
{
  
}

void fill_matrix(star_t * array, float_t **matrix, int size)
{
  
}

void print_matrix(float_t** theMatrix, int n)
{
  int i, j;
  for(i = 0 ; i < n; i++)
  {
    printf("%d ", i);
    for(j = 0 ; j < n ; j++)
	  printf("%2.3f " , theMatrix[i][j]);
    putchar('\n');
   }
}

hist_param_t generate_histogram(float_t **matrix, int *histogram, int mat_size, int hist_size)
{
  
}

void display_histogram(int *histogram, hist_param_t histparams)
{
   int i,j;

   for(i = 0; i < histparams.hist_size && histparams.bin_size*i < histparams.max; i++)
   {
      printf("%1.3e\t", histparams.bin_size*i+histparams.min);
   }
   printf("%1.2e\n", histparams.max);
  // printf("****\n");
   for(j = 0; j < i; j++)
   {
      printf("%d\t\t", histogram[j]);
   }
   printf("\n");
}
