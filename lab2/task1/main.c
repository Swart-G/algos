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

    int err = scan_array(array, size);
    if (err != 0) {
        printf("Ошибка чтения массива: %d\n", err);

        free(array);
        return err;
    }

    err = reverse_array(array, size);
    if (err != 0) {
        printf("Ошибка разворота: %d\n", err);

        free(array);
        return err;
    }

    printf("Массив в обратном порядке:\n");
    err = print_array(array, size);
    if (err != 0) {
        printf("Ошибка вывода массива: %d\n", err);

        free(array);
        return err;
    }

    free(array);

    return 0;
}
