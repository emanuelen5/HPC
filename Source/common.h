/*****
 *  Solution to examination project in High Performance Computing and Programming
 * 
 *  funcs.h functions header file
 *
 * Author: Marcus Holm
 * Edits: Erasmus Cedernaes
 *
 **/

#ifndef _COMMON_H
#define _COMMON_H


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define float_t float 
#define NUM_HIST_BOXES 10

// Star struct
typedef struct star{
  int index;                    // counting index
  char spectralType;            // random: O, B, A, F, G, K, M, L, T
  unsigned short subType;       // random: 0-9
  float_t magnitude;            // random: (-10, +20)
  char designation[7]; 	        // sprintf(“%c%d.%s”, spectralType, subType, itoa(index)) 
  struct pos{
     float_t x, y, z;           // x & y random in (-1e5, 1e5), z random in (-3e3, 3e3)
  } position;
} star_t;

// Histogram struct
typedef struct hist_params{
   int hist_size;               // number of bins
   float_t min, max, bin_size;  // minimum, maximum value as well as width of bins
} hist_param_t;

#endif
