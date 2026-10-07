#include <stdio.h>

int main() {
    int count;
    double current;
    double sum = 0;
    double sq_sum = 0;
    int i = 0;
    printf("Введите натуральное число n, количество элементов последовательности:\n");
    scanf("%d", &current);
    for(i; i < count; i++){
        printf("Введите элемент %d: ", i+1);
        scanf("%lf", &current);
        sum += current;
        sq_sum += current * current;
    }
    printf("Дисперсия последовательности: %f\n", sq_sum / current - (sum / current) * (sum / current));
    return 0;
}