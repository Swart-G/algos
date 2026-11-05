#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "array.h"

int main() {
    int size;
    int target_index;



    printf("Введите длину массива:\n");
    if (scanf("%d", &size) != 1) {
        printf("Некорректный ввод: %d\n", EIO);
        return EIO;
    }
    if (size <= 0) {
        printf("Некорректный аргумент: %d\n", EINVAL);
        return EINVAL;
    }

    printf("Введите искомый индекс (нумерация с 0):\n");
    if (scanf("%d", &target_index) != 1) {
        printf("Некорректный ввод: %d\n", EIO);
        return EIO;
    }
    if (0 > target_index || target_index >= size) {
        printf("Некорректный аргумент: %d\n", EINVAL);
        return EINVAL;
    }

    int *array = (int*) malloc(size * sizeof(int));
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



    err = quick_select(array, size, target_index);
    if (err != 0) {
        printf("Ошибка поиска элемента: %d\n", err);

        free(array);
        return err;
    }

    printf("Искомый элемент:\n");
    if (printf("%d", array[target_index]) < 0) {
        printf("Некорректный ввод: %d\n", EIO);
        free(array);
        return EIO;
    }

    free(array);
    return 0;
}
