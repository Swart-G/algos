#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "array.h"

int main() {
    int arr_len;
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
        printf("Ошибка выделения памяти\n");

        return ENOMEM;
    }

    if (scan_array(arr, arr_len) != 0) {
        printf("Ошибка чтения массива\n");

        free(arr);
        return EIO;
    }

    if (reverse_array(arr, arr_len) != 0) {
        printf("Ошибка разворота\n");

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
