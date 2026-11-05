
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

long long count_inversions(int *array, int *buffer, int left_index, int right_index) {
    if (left_index == right_index) {
        return 0;
    }
    int middle_index = left_index + (right_index - left_index) / 2;

    long long count_left_inversions = count_inversions(array, buffer, left_index, middle_index);
    long long count_right_inversions = count_inversions(array, buffer, middle_index + 1, right_index);

    long long merge_count_inversions = merge_count(array, buffer, left_index, middle_index, right_index);

    return count_left_inversions + count_right_inversions + merge_count_inversions;
}

long long merge_count(int *array, int *buffer, int left_index, int middle_index, int right_index){
    long long inversions = 0;
    int i = left_index;
    int j = middle_index + 1;
    int writing_index = left_index;

    while (i <= middle_index && j <= right_index) {
        if (array[i] <= array[j]) {
            buffer[writing_index] = array[i];
            i++;
        } else {
            buffer[writing_index] = array[j];
            inversions += middle_index - i + 1;
            j++;
        }
        writing_index++;
    }

    while (i <= middle_index) {
        buffer[writing_index] = array[i];
        writing_index++;
        i++;
    }
    while (j <= right_index) {
        buffer[writing_index] = array[j];
        writing_index++;
        j++;
    }
    for (i = left_index; i <= right_index; i++) {
        array[i] = buffer[i];
    }
    return inversions;
}
