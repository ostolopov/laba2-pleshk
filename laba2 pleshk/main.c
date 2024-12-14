#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "arr_func.h"
#include "lab2_func.h"

int main(void) {
    int *arr_first = NULL;
    int **arr_second = NULL;
    int arr_size = 0;
    int arr_size_x = 0;
    int arr_size_y = 0;
    int case_number = 0;
    printf("(1) Инициализация одномерного массива.\n(2) Инициализация двумерного массива.\n(3) Вывод одномерного массива.\n(4) Вывод двумерного массива.\n(5) Поменять местами максимальный и минимальный элементы массива.\n(6) Все элементы массива, меньшие заданного значения, и их номера записать в два новых массива (в один значения в другой номера).\n(7) Вводится дополнительный массив разрешенных значений. Определить и вывести на экран, сколько элементов исходного массива имеют разрешенные значения.\n(8) Составить и вывести на экран массив из различных (по значению) элементов исходного массива.\n(9) Составить и вывести на экран два массива: массив повторяющихся элементов исходного массива и массив их частот.\n\n");
    while (get_int(&case_number, 0 ,15) != -1  && case_number != 0)
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
            case 4:
                arr_second_print(arr_second, arr_size_x, arr_size_y);
                break;
            case 5:
                min_max(arr_first, arr_size);
                break;
            case 6:
                arr_under_num(arr_first, arr_size);
                break;
            case 7:
                additional_arr(arr_first, arr_size);
                break;
            case 8:
                remove_duplicates(arr_first, arr_size);
                break;
            case 9:
                count_duplicates(arr_first, arr_size);
                break;
            case 15:
                system("clear");
                break;
            default:
                printf("Жмакнули не ту кнопку\n");
                break;
        }
        printf("(1) Инициализация одномерного массива.\n(2) Инициализация двумерного массива.\n(3) Вывод одномерного массива.\n(4) Вывод двумерного массива.\n(5) Поменять местами максимальный и минимальный элементы массива.\n(6) Все элементы массива, меньшие заданного значения, и их номера записать в два новых массива (в один значения в другой номера).\n(7) Вводится дополнительный массив разрешенных значений. Определить и вывести на экран, сколько элементов исходного массива имеют разрешенные значения.\n(8) Составить и вывести на экран массив из различных (по значению) элементов исходного массива.\n(9) Составить и вывести на экран два массива: массив повторяющихся элементов исходного массива и массив их частот.\n\n");
    }
    free(arr_first);
    arr_second_free(arr_second, arr_size_x);
    return 0;
}
