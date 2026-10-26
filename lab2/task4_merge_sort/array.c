
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


int merge_sort(int *array, int left_index, int right_index){
    if (array == NULL || left_index < 0 || right_index < left_index) {
        return EINVAL;
    }
    if (left_index == right_index) {
        return 0;
    }
    int middle_index = left_index + (right_index - left_index) / 2;

    int err = merge_sort(array, left_index, middle_index);
    if (err != 0) {
        return err;
    }
    err = merge_sort(array, middle_index + 1, right_index);
    if (err != 0) {
        return err;
    }
    return merge_groups(array, left_index, middle_index, right_index);
}

int merge_groups(int *array, int left_index, int middle_index, int right_index){
    int i = left_index;
    int j = middle_index + 1;

    while (i <= middle_index && j <= right_index) {
        if (array[i] <= array[j]) {
            i++;
        } else {
            int err = shift_array(array + i, j-i+1, 1);
            if (err != 0) {
                return err;
            }
            i++;
            j++;
            middle_index++;
        }
    }
    return 0;
}
