#include <stdio.h>

int main()
{
    int count;
    double current;
    double sum = 0;
    double sq_sum = 0;
    int i = 0;
    printf("Введите натуральное число n, количество элементов последовательности:\n");
    if (scanf("%d", &count) == 0 || count < 1) {
        printf("Некорректный ввод");
        return 1;
    }
    for (i; i < count; i++) {
        printf("Введите элемент %d: ", i + 1);
        if (scanf("%lf", &current) == 0) {
            printf("Некорректный ввод");
            return 1;
        }
        sum += current;
        sq_sum += current * current;
    }
    printf("Дисперсия последовательности: %f\n", sq_sum / count - (sum / count) * (sum / count));
    return 0;
}