#include "lab2_func.h"

void min_max (int *arr, int arr_size)
{
    int *arr_local =  malloc(arr_size * sizeof(int));
    int max_index = 0;
    int min_index = 0;
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i < arr_size; i++)
    {
        arr_local[i] = arr[i];
    }
    for (int i = 1; i < arr_size; i++)
    {
        if (arr_local[i] < min)
        {
            min = arr_local[i];
            min_index = i;
        } else if (arr_local[i] > max)
        {
            max = arr_local[i];
            max_index = i;
        }
    }
    int temp = arr_local[min_index];
    arr_local[min_index] = arr_local[max_index];
    arr_local[max_index] = temp;
    arr_first_print(arr_local, arr_size);
    free(arr_local);
}

void arr_under_num (int *arr, int arr_size)
{
    int *arr_final = malloc(arr_size * sizeof(int));
    int *arr_index = malloc(arr_size * sizeof(int));
    int final_size = 0;
    int number = 0;
    for (int i = 0; i < arr_size; i++)
    {
        arr[i] = arr[i];
    }
    printf("Введите значение: \n");
    get_int(&number, INT_MIN, INT_MAX);
    for (int i = 0; i < arr_size; i++)
    {
        if(arr[i] < number)
        {
            arr_final[final_size] = arr[i];
            arr_index[final_size] = i;
            final_size += 1;
        }
    }
    arr_final = realloc(arr_final, final_size * sizeof(int));
    arr_index = realloc(arr_index, final_size * sizeof(int));
    printf("Конечный массив: \n");
    arr_first_print(arr_final, final_size);
    printf("Массив индексов: \n");
    arr_first_print(arr_index, final_size);
    free(arr_final);
    free(arr_index);
}

void additional_arr(int *arr, int arr_size)
{
    int count = 0;
    int *arr_addit = NULL;
    int arr_addit_size = 0;
    arr_first_inicialization (&arr_addit, &arr_addit_size);
    //remove_duplicates(&arr_addit, &arr_addit_size);
    //arr_first_print(arr_addit, arr_addit_size);
    //printf("%d\n", arr_addit_size);
    for (int i = 0; i < arr_size; i++)
    {
        for (int j = 0; j < arr_addit_size; j++)
        {
            if (arr[i] == arr_addit[j])
            {
                count++;
                break;
            }
        }
    }
    printf("Количество элементов имеющих разрешенное значение: %d\n", count);
    free(arr_addit);
}


void remove_duplicates(int **arr, int *arr_size) {
    int *new_arr = malloc(*arr_size * sizeof(int));
    int new_arr_size = 0;
    for (int i = 0; i < *arr_size; i++) {
        int flag = 0;
        for (int j = 0; j < new_arr_size; j++) {
            if ((*arr)[i] == new_arr[j]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            new_arr[new_arr_size++] = (*arr)[i];
        }
    }
    for (int i = 0; i < new_arr_size; i++) {
        (*arr)[i] = new_arr[i];
    }
    *arr_size = new_arr_size;
    new_arr = realloc(new_arr, new_arr_size * sizeof(int));
}

