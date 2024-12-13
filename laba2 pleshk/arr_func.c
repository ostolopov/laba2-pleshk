#include "arr_func.h"

int get_int(int *number, int min, int max){
        int check = 0, number_check, flag = 0;
        while(flag == 0){
                check = scanf("%d" , &number_check);
                switch(check){
                        case EOF:
                                printf("Работа программы прекращена.\n");
                                flag = 1;
                                break;
                        case 1 :
                                if (number_check < min || number_check > max)
                                {
                                    printf("Число вышло за разрешенный диапазон. Попробуйте еще раз!\n");
                                    scanf("%*[^\n]");
                                    flag = 0;
                                    break;
                                }
                                *number = number_check;
                                scanf("%*[^\n]");
                                flag = 1;
                                break;
                        case 0:
                                printf("Число неверно. Попробуйте еще раз!\n");
                                scanf("%*[^\n]");
                                flag = 0;
                                break;
                        
                }
        }
        return check;
}

void arr_first_inicialization (int **arr, int *arr_size)
{
    int arr_size_local = 0;
    int arr_element;
    printf("Введите размер массива: \n");
    get_int(&arr_size_local, 1, INT_MAX);
    *arr = realloc(*arr, arr_size_local * sizeof(int));
    for (int i = 0; i < arr_size_local; i++)
    {
        printf("arr[%d] = ", i);
        get_int(&arr_element, INT_MIN, INT_MAX);
        (*arr)[i] = arr_element;
        
    }
    *arr_size = arr_size_local;
}

void arr_second_inicialization (int ***arr, int *n, int *m)
{
    int n_local = 0;
    int m_local = 0;
    int arr_element;
    printf("Введите количество строк: \n");
    get_int(&n_local, 1, INT_MAX);
    printf("Введите количество столбцов: \n");
    get_int(&m_local, 1, INT_MAX);
    *arr = malloc(n_local * sizeof(int*));
    for (int i = 0; i < n_local; i++)
    {
        (*arr)[i] = malloc(m_local * sizeof(int));
    }
    for (int i = 0; i < n_local; i++)
    {
        for (int j = 0; j < m_local; j++)
        {
            printf("arr[%d][%d] = ", i, j);
            get_int(&arr_element, INT_MIN, INT_MAX);
            (*arr)[i][j] = arr_element;
        }
    }
    *n = n_local;
    *m = m_local;
}

void arr_second_free(int **arr, int n) {
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}

void arr_first_print (int *arr, int arr_size)
{
    if (arr_size == 0)
    {
        printf("Массив не инициализирован\n");
        return;
    }
    int arr_element = 0;
    for (int i = 0; i < arr_size; i++)
    {
        arr_element = arr[i];
        printf("arr[%d] = %d\n", i , arr_element);
    }
}

void arr_second_print (int **arr, int n, int m)
{
    if (n == 0 || m == 0)
    {
        printf("Массив не инициализирован\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%3.d ", arr[i][j]);
        }
        printf("\n");
    }
}


void delete_element(int *arr_size, int **arr, int element_id)
{
    for (int i = 0; i < *arr_size - 1; i++)
    {
        if (element_id > i)
        {
            (*arr)[i] = (*arr)[i];
        }
        else
        {
            (*arr)[i] = (*arr)[i+1];
        }
    }
    *arr_size -= 1;
}


/*
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
*/
