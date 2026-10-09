#include <stdio.h>

int main() {
    int sequence_len;
    double previous;
    double current;
    int i = 1;
    int count = 1;

    printf("Введите натуральное число n, количество элементов последовательности:\n");
    if (scanf("%d", &sequence_len) != 1 || sequence_len < 1) {
        printf("Некорректный ввод");
        return 1;
    }

    printf("Введите элемент 1: ");
    if (scanf("%lf", &previous) != 1) {
        printf("Некорректный ввод");
        return 1;
    }

    for (; i < sequence_len; i++) {
        printf("Введите элемент %d: ", i + 1);
        if (scanf("%lf", &current) != 1) {
            printf("Некорректный ввод");
            return 1;
        }

        if (current > previous) {
            count++;
        }
        previous = current;
    }

    printf("Количество уникальных членов последовательности: %d\n", count);
    return 0;
}
