#include <stdio.h>
#include <stdlib.h>

int main() {
    int sequence_len;
    int unique_count = 0;
    int i, j;

    double current;

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

        for (j = 0; j < i; j++) {
            if (arr[j] == current) {
                break;
            }
        }
        if (j!=i) {
            unique_count++;
        }

        arr[i] = current;
    }

    // realloc(arr...);

    printf("Количество уникальных членов последовательности: %d\n", unique_count);
    for (i = 0; i < sequence_len; i++) {
        printf("%.20lf\n", arr[i]);
    }

    free(arr);
    return 0;
}
