#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "reverse_array.h"


int main() {
    int arr_len;
    int current;
    printf("Введите длину массива:\n");

    if (scanf("%d", &arr_len) != 1) {
        printf("Некорректный ввод");
        return EIO;
    }

    int* arr = (int*) malloc(arr_len * sizeof(int));
    for (int i = 0; i < arr_len; i++) {
        printf("Введите %d член массива:\n", i+1);
        if (scanf("%d", &current) != 1) {
            printf("Некорректный ввод");
            return EIO;
        }
        arr[i] = current;
    }

    if (reverse_array(arr, arr_len) != 0) {
        printf("Ошибка reverse");
        return 1;
    }

    for (int i = 0; i < arr_len; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}