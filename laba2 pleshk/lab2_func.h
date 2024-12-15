#ifndef lab2_func_h
#define lab2_func_h

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "arr_func.h"

void min_max (int *arr, int arr_size);
void arr_under_num (int *arr, int arr_size);
void additional_arr (int *arr_first, int arr_size);
void remove_duplicates(int *arr, int arr_size);
void count_duplicates(int *arr, int arr_size);
void count_negative (int **arr, int n, int m);
void arithmetic_mean (int **arr,int n, int m);
void min_number (int **arr, int n, int m);
void max_index (int **arr, int n, int m);
void prime_number_count (int **arr, int n, int m);

#endif
