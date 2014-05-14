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
  int i;
  for(i = 0; i < size, i++)
  {
    stars[i].index = i;
    char randChar = rand() % 9;
    switch(randChar) {
        case 0:
          randChar = 'O';
        break;
        case 1:
          randChar = 'B';
        break;
        case 2:
          randChar = 'A';
        break;
        case 3:
          randChar = 'F';
        break;
        case 4:
          randChar = 'G';
        break;
        case 5:
          randChar = 'K';
        break;
        case 6:
          randChar = 'M';
        break;
        case 7:
          randChar = 'L';
        break;
        case 8:
          randChar = 'T';
        break;
    }
    stars[i].subType = rand() % 10; // 0-9
    stars[i].magnitude = 30.0f * (float)rand()/RAND_MAX - 10.0f; // (-10, 20)
    stars[i].designation[7]; 
    sprintf(stars[i].designation, “%c%d.%s”, spectralType, subType, itoa(index)); //
    stars[i].pos.x = 2e-5*(float)rand()/RAND_MAX - 2e-5;
    stars[i].pos.y = 2e-5*(float)rand()/RAND_MAX - 2e-5;
    stars[i].pos.z = 6e-3*(float)rand()/RAND_MAX - 3e-3;
  } 
}

void print_stars(star_t* array, int n)
{
   int i;
   for(i = 0; i<n; i++)
      printf("%s ", array[i].designation);
   printf("\n");
}




void sort(star_t* array, int n) 
{
  int i, j;
  for(i = 1; i < n; i++) {
    for(j = 0; j < i; j++) {
      double dist_a = sqrt(array[i].x*array[i].x + array[i].y*array[i].y + array[i].z*array[i].z);
      double dist_b = sqrt(array[j].x*array[j].x + array[j].y*array[j].y + array[j].z*array[j].z);
      if(a < b) {
        star_t tempStar = array[i];
        array[i] = array[j];
        array[j] = tempStar;
      }
    }
  }

}

void fill_matrix(star_t* array, float_t** matrix, int size)
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
