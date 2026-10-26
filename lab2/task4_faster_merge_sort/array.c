
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



int merge_sort(int *array, int *buffer, int left_index, int right_index){
    if (left_index == right_index) {
        return 0;
    }
    int middle_index = left_index + (right_index - left_index) / 2;

    int err = merge_sort(array, buffer, left_index, middle_index);
    if (err != 0) {
        return err;
    }
    err = merge_sort(array, buffer, middle_index + 1, right_index);
    if (err != 0) {
        return err;
    }
    return merge_groups(array, buffer, left_index, middle_index, right_index);
}

int merge_groups(int *array, int *buffer, int left_index, int middle_index, int right_index){
    int i = left_index;
    int j = middle_index + 1;
    int writing_index = left_index;

    while (i <= middle_index && j <= right_index) {
        if (array[i] <= array[j]) {
            buffer[writing_index] = array[i];
            i++;
        } else {
            buffer[writing_index] = array[j];
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
    return 0;
}
