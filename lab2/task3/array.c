
#include <stdio.h>
#include <errno.h>
#include "array.h"

int print_array(int *array, int size) {
    if (array == NULL || size <= 0) {
        return EINVAL;
    }

    int i;
    for (i = 0; i < size; i++) {
        if (printf("%d ", array[i]) < 0) {
            return EIO;
        }
    }
    if (printf("\n") < 0) {
        return EIO;
    }
    return 0;
}

int scan_array(int *array, int size) {
    if (array == NULL || size <= 0) {
        return EINVAL;
    }

    int i;
    for (i = 0; i < size; i++) {
        printf("Введите %d член массива:\n", i+1);
        if (scanf("%d", &array[i]) != 1) {
            return EIO;
        }
    }
    return 0;
}

int reverse_array(int* array, int size) {
    if (array == NULL || size <= 0) {
        return EINVAL;
    }

    for (int i = 0; i < size/2; i++) {
        int temp = array[i];

        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
    return 0;
}

int shift_array(int *array, int size, int shift_step) {
    if (array == NULL || size <= 0) {
        return EINVAL;
    }

    shift_step %= size;
    if (shift_step < 0) {
        shift_step += size;
    }
    if (shift_step == 0) {
        return 0;
    }

    reverse_array(array, size);
    reverse_array(array, shift_step);
    reverse_array(array+shift_step, size-shift_step);
    return 0;
}

int strange_sort (int *array, int size) {
    if (array == NULL || size <= 0) {
        return EINVAL;
    }

    int group_end = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            shift_array(array + group_end, i - group_end + 1, 1);
            group_end++;
        }
    }


    for (int i = group_end; i < size; i++) {
        if (array[i] == 0) {
            shift_array(array + group_end, i - group_end + 1, 1);
            group_end++;
        }
    }

    return 0;
}
