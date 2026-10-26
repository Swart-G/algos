#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "array.h"

int main() {
    int size;
    int shift_step;

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

    int err = scan_array(array, size);
    if (err != 0) {
        printf("Ошибка чтения массива: %d\n", err);

        free(array);
        return err;
    }

    printf("Введите шаг сдвига массива:\n");
    if (scanf("%d", &shift_step) != 1) {
        printf("Некорректный ввод: %d\n", EIO);

        free(array);
        return EIO;
    }

    err = shift_array(array, size, shift_step);
    if (err != 0) {
        printf("Ошибка сдвига: %d\n", err);

        free(array);
        return err;
    }

    printf("Массив после циклического сдвига:\n");
    err = print_array(array, size);
    if (err != 0) {
        printf("Ошибка вывода массива: %d\n", err);

        free(array);
        return err;
    }

    free(array);

    return 0;
}
