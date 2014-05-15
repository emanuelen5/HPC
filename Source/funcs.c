/*****
 *  Solution to examination project in High Performance Computing and Programming
 * 
 *  funcs.c functions implementation file
 *
 * Author: Marcus Holm
 * Edits: Erasmus Cedernaes
 *
 **/

#include "common.h"
#include "funcs.h"

void create_random_array(star_t * stars, int size)
{
  int i;
  for(i = 0; i < size, i++) {
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
  int i, j;
  for(i = 0; i < size; i++) {
    for(j = 0; j < size; j++) {
      matrix[i][j] = sqrt((array[i].pos.x - array[j].pos.x)*(array[i].pos.x - array[j].pos.x) + (array[i].pos.y - array[j].pos.y)*(array[i].pos.y - array[j].pos.y));
    }
  }
}

void print_matrix(float_t** theMatrix, int n)
{
  int i, j;
  for(i = 0 ; i < n; i++) {
    printf("%d ", i);
    for(j = 0 ; j < n ; j++)
      printf("%2.3f " , theMatrix[i][j]);
    putchar('\n');
   }
}

// typedef struct hist_params{
//    int hist_size;
//    float_t min, max, bin_size;
// } hist_param_t;

hist_param_t generate_histogram(float_t** matrix, int* histogram, int mat_size, int hist_size)
{
  int i, j;
  float_t sum = 0.0f;
  float_t e;

  // Malloc result matrix
  float_t** vN_mean = (float_t**) malloc(mat_size-2*sizeof(float_t*));
  for(i = 1; i < mat_size-1)
    vN_mean[i] = (float_t*) malloc(mat_size-2*sizeof(float_t));

  // Calculate mean value of absolute difference between elements in von Neumann neighborhood
  for(i = 1; i < mat_size-1; i++) {
    for(j = 1; j < mat_size-1; j++) {
      e = matrix[i][j];
      vN_mean[i-1][j-1] = abs(matrix[i-1][j] - e) + abs(matrix[i+1][j] - e) + abs(matrix[i][j-1] - e) + abs(matrix[i][j+1] - e);
      vN_mean[i-1][j-1] /= 4;
    }
  }

  // Find min and max
  float_t minMax[2];
  minMax[0] = vN_mean[0][0];
  minMax[1] = minMax[0];
  for(i = 0; i < mat_size; i++) {
    for(j = 0; j < mat_size; j++) {
      e = vN_mean[i][j];
      if(e < minMax[0]) {
        minMax[0] = e;
      } else if(e > minMax[1]) {
        minMax[1] = e;
      }
    }
  }

  // Count values in ranges for histogram
  int l;
  float_t interval = (minMax[1] - minMax[0])/hist_size;
  for(i = 0; i < mat_size; i++) {
    for(j = 0; j < mat_size; j++) {
      for(l = 0; l < hist_size; l++) {
        if((vN_mean[i][j] >= minMax[0] + interval*l) && (vN_mean[i][j] <= minMax[0] + interval*l*2)) {
          histogram[l]++;
        }
      }
    }
  }

  // Copy information to histogram struct
  hist_param_t hist;
  hist.hist_size = hist_size;
  hist.min = minMax[0];
  hist.max = minMax[1];
  hist.bin_size = interval;

  return hist;
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
