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

int reverse_array(int* array, int length) {
    if (array == NULL || length <= 0) {
        return EINVAL;
    }

    for (int i = 0; i < length/2; i++) {
        int current = array[i];

        array[i] = array[length - i - 1];
        array[length - i - 1] = current;
    }
    return 0;
}

int shift_array(int *array, int length, int shift_step) {
    if (array == NULL || length <= 0) {
        return EINVAL;
    }

    shift_step %= length;
    if (shift_step < 0) {
        shift_step += length;
    }
    if (shift_step == 0) {
        return 0;
    }

    reverse_array(array, length);
    reverse_array(array, shift_step);
    reverse_array(array+shift_step, length-shift_step);
    return 0;
}