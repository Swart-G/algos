#include <stdio.h>

int main() {
    int sequence_len;
    int count = 0;
    double min;
    double current;
    int i = 1;

    printf("Введите натуральное число n, количество элементов последовательности:\n");
    if (scanf("%d", &sequence_len) != 1 || sequence_len < 1) {
        printf("Некорректный ввод");
        return 1;
    }

    printf("Введите элемент 1: ");
    if (scanf("%lf", &current) != 1) {
        printf("Некорректный ввод");
        return 1;
    }
    min = current;
    count = 1;

    for (; i < sequence_len; i++) {
        printf("Введите элемент %d: ", i + 1);
        if (scanf("%lf", &current) != 1) {
            printf("Некорректный ввод");
            return 1;
        }
        if (current < min) {
            min = current;
            count = 1;
        } else if (current == min) {
            count++;
        }
    }

    printf("Количество минимальных элементов в последовательности: %d\n", count);
    return 0;
}
