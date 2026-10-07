#include <stdio.h>

int main() {
    int count;
    double current;
    double sum = 0;
    int i = 0;
    printf("Введите натуральное число n, количество элементов последовательности:\n");
    scanf("%d", &count);
    for(int i = 0; i < count; i++){
        printf("Введите элемент %d: ", i+1);
        scanf("%lf", &current);
        sum += current;
    }
    printf("Математическое ожидание последовательности: %f\n", sum/current);
    return 0;
}