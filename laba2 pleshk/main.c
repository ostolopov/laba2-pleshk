#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
    get_int(&arr_size_local, 0, INT_MAX);
    *arr = realloc(*arr, arr_size_local * sizeof(int));
    for (int i = 0; i < arr_size_local; i++)
    {
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
    get_int(&n_local, 0, INT_MAX);
    printf("Введите количество столбцов: \n");
    get_int(&m_local, 0, INT_MAX);
    **arr = malloc(n_local * sizeof(int));
    for (int i = 0; i < m_local; )
    
    
    *n = n_local;
    *m = m_local;
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
    
}

int main(void) {
    int *arr_first = NULL;
    int **arr_second = NULL;
    int arr_size = 0;
    int arr_size_x = 0;
    int arr_size_y = 0;
    int case_number = 0;
    printf("(1) Инициализация одномерного массива.\n(2) Инициализация двумерного массива.\n(3) Вывод одномерного массива.\n(4) Вывод двумерного массива.\n\n");
    while (get_int(&case_number, 0 ,7) != -1 && case_number != 0)
    {
        switch (case_number)
        {
            case 1:
                arr_first_inicialization(&arr_first, &arr_size);
                break;
            case 2:
                arr_second_inicialization(&arr_second, &arr_size_x, &arr_size_y);
            case 3:
                arr_first_print(arr_first, arr_size);
                break;
            default:
                printf("Жмакнули не ту кнопку\n");
                break;
        }
        printf("(1) Инициализация одномерного массива.\n(2) Инициализация двумерного массива.\n(3) Вывод одномерного массива.\n(4) Вывод двумерного массива.\n\n");
    }
    free(arr_first);
    free(arr_second);
    return 0;
}
