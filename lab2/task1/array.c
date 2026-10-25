#include <stdio.h>
#include <errno.h>
#include "array.h"

int print_array(int *array, int length) {
    if (array == NULL || length <= 0) {
        return EINVAL;
    }

    int i;
    for (i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}

int scan_array(int *array, int length) {
    if (array == NULL || length <= 0) {
        return EINVAL;
    }

    int i;
    for (i = 0; i < length; i++) {
        printf("Введите %d член массива:\n", i+1);
        if (scanf("%d", &array[i]) != 1) {
            return EIO;
        }
    }
    return 0;
}

int reverse_array(int* arr, int length) {
    if (arr == NULL || length <= 0) {
        return EINVAL;
    }

    for (int i = 0; i < length/2; i++) {
        int current = arr[i];

        arr[i] = arr[length - i - 1];
        arr[length - i - 1] = current;
    }
    return 0;
}
