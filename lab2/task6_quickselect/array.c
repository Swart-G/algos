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


void item_swap(int *array, int i, int j) {
    int temp;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int quick_select(int *array, int size, int target_index) {
    if (array == NULL || size <= 0 || 0 > target_index || target_index >= size) {
        return EINVAL;
    }
    if (size == 1) {
        return 0;
    }

    int pivot = array[size/2];
    int i = 0, j = size - 1;

    while (i <= j) {
        while (array[i] < pivot) {
            i++;
        }
        while (array[j] > pivot) {
            j--;
        }
        if (i > j) {
            break;
        }
        item_swap(array, i, j);
        i++;
        j--;
    }

    if (target_index <= j) {
        return quick_select(array, j+1, target_index);
    }
    if (target_index >= i) {
        return quick_select(array + i, size - i, target_index - i);
    }
    return 0;
}
