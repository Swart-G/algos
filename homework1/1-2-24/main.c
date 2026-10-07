#include <stdio.h>

int main()
{
    int sequence_len;
    double min;
    double max;
    double current;
    int i = 0;

    printf("Введите натуральное число n, количество элементов последовательности:\n");
    if (scanf("%d", &sequence_len) == 0 || sequence_len < 1) {
        printf("Некорректный ввод");
        return 1;
    }

    for (i; i < sequence_len; i++) {
        printf("Введите элемент %d: ", i + 1);
        if (scanf("%lf", &current) == 0) {
            printf("Некорректный ввод");
            return 1;
        }

        if (i == 0) {
            min = current;
            max = current;
        } else {
            if (current < min) {
                min = current;
            }
            if (current > max) {
                max = current;
            }
        }
    }

    printf("Максимальный член последовательности: %lf\n", max);
    printf("Минимальный член последовательности: %lf\n", min);
    return 0;
}