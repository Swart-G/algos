#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "array.h"

int main() {
    int size;

    printf("Введите длину массива:\n");
    if (scanf("%d", &size) != 1) {
        printf("Некорректный ввод: %d\n", EIO);
        return EIO;
    } else if (size <= 0) {
        printf("Некорректный аргумент: %d\n", EINVAL);
        return EINVAL;
    }

    int* array = (int*) malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Ошибка выделения памяти: %d\n", ENOMEM);

        return ENOMEM;
    }
    int* buffer = (int*) malloc(size * sizeof(int));
    if (buffer == NULL) {
        printf("Ошибка выделения памяти: %d\n", ENOMEM);

        free(array);
        return ENOMEM;
    }

    int err = scan_array(array, size);
    if (err != 0) {
        printf("Ошибка чтения массива: %d\n", err);

        free(array);
        free(buffer);
        return err;
    }



    err = merge_sort(array, buffer, 0, size - 1);
    if (err != 0) {
        printf("Ошибка сортировки массива: %d\n", err);

        free(array);
        free(buffer);
        return err;
    }

    printf("Массив после сортировки слиянием:\n");
    err = print_array(array, size);
    if (err != 0) {
        printf("Ошибка вывода массива: %d\n", err);

        free(array);
        free(buffer);
        return err;
    }

    free(array);
    free(buffer);
    return 0;
}
