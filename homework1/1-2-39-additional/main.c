#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int sequence_len;
    int unique_count = 0;
    int i, j;

    double current;

    bool is_unique;

    printf("Введите натуральное число n, количество элементов последовательности:\n");
    if (scanf("%d", &sequence_len) != 1 || sequence_len < 1) {
        printf("Некорректный ввод");
        return 1;
    }

    double *arr = malloc(sizeof(double) * sequence_len);
    if (arr == NULL) {
        printf("Ошибка выделения памяти");
        return 1;
    }

    for (i = 0; i < sequence_len; i++) {
        if (scanf("%lf", &current) != 1) {
            printf("Некорректный ввод");
            free(arr);
            return 1;
        }

        is_unique = true;
        for (j = 0; j < i; j++) {
            if (arr[j] == current) {
                is_unique = false;
                break;
            }
        }
        if (is_unique) {
            unique_count++;
        }

        arr[i] = current;
    }

    free(arr);

    printf("Количество уникальных членов последовательности: %d\n", unique_count);
    return 0;
}
