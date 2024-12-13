#ifndef arr_func_h
#define arr_func_h

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int get_int(int *number, int min, int max);
void arr_first_inicialization (int **arr, int *arr_size);
void arr_second_inicialization (int ***arr, int *n, int *m);
void arr_second_free(int **arr, int n);
void arr_first_print (int *arr, int arr_size);
void arr_second_print (int **arr, int n, int m);
void delete_element(int *arr_size, int **arr, int element_id);

#endif
