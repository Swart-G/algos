#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "array.h"

int main() {
    int arr_len;
    int shift_step;

    printf("Введите длину массива:\n");
    if (scanf("%d", &arr_len) != 1) {
        printf("Некорректный ввод\n");
        return EIO;
    } else if (arr_len <= 0) {
        printf("Некорректный аргумент\n");
        return EINVAL;
    }

    int* arr = (int*) malloc(arr_len * sizeof(int));
    if (arr == NULL) {
        printf("Ошиба выделения памяти\n");

        return ENOMEM;
    }

    if (scan_array(arr, arr_len) != 0) {
        printf("Ошибка чтения массива\n");

        free(arr);
        return EIO;
    }

    printf("Введите шаг сдвига массива:\n");
    if (scanf("%d", &shift_step) != 1) {
        printf("Некорректный ввод\n");

        free(arr);
        return EIO;
    }

    if (shift_array(arr, arr_len, shift_step) != 0) {
        printf("Ошибка сдвига\n");

        free(arr);
        return 1;
    }

    if (print_array(arr, arr_len) != 0) {
        printf("Ошибка вывода массива\n");

        free(arr);
        return EIO;
    }

    free(arr);

    return 0;
}