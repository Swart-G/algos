#include <stdio.h>

int main() {
    int count;
    double current;
    double sum = 0;
    int i = 0;
    printf("Введите натуральное число n, количество элементов последовательности:\n");
    if (scanf("%d", &count) != 1 || count < 1) {
        printf("Некорректный ввод");
        return 1;
    }
    for (; i < count; i++) {
        printf("Введите элемент %d: ", i + 1);
        if (scanf("%lf", &current) != 1) {
            printf("Некорректный ввод");
            return 1;
        }
        sum += current;
    }
    printf("Математическое ожидание последовательности: %f\n", sum / count);
    return 0;
}
