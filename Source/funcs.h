/*****
 *  Solution to examination project in High Performance Computing and Programming
 * 
 *  funcs.h functions header file
 *
 * Author: Marcus Holm
 * Edits: Erasmus Cedernaes
 *
 **/

#ifndef _FUNCS_H
#define _FUNCS_H

// Creates a star array with random content according to the specifications
// @param stars Array of allocated stars to fill [star_t*]
// @param size Elements in the allocated array of stars [int]
void create_random_array(star_t* array, int size);

// Sorts the stars according to their distance to the origin
// @param array Array of stars to sort [star_t*]
// @param n Elements in the array [int]
void sort(star_t* array, int n);

// Prints the star array of size n
// @param array Array of stars to print [star_t*]
// @param n Number of elements in the array [int]
void print_stars(star_t* array, int n);

// Fills a matrix with elements that represent the distance between star i and star j.
// @param array Array to measure distance between stars [star_t]
// @param matrix Matrix to fill with distance information [float**]
// @param size Size of the array [int]
void fill_matrix(star_t* array, float_t** matrix, int size);

// Prints the matrix array of size n*n
// @param matrix Matrix to print [float**]
// @param n The side of the (square) matrix [int]
void print_matrix(float_t** matrix, int n);

// Generates a histogram struct
// @param matrix Matrix with elements to count [float**]
// @param histogram Where to store result of number of counted elements in each bin [int*]
// @param mat_size Side length of square matrix with elements to count [int]
// @param hist_size Amount of bins in histogram [int]
hist_param_t generate_histogram(float_t** matrix, int* histogram, int mat_size, int hist_size);

// Displays a histogram 
// @param histogram Where the result of number of counted elements in each bin is stored [int*]
// @param histparams Additional histogram parameters in struct [hist_param_t] 
void display_histogram(int* histogram, hist_param_t histparams);
#endif
