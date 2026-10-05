#include <stdio.h>

int main() {
    int n;
    double x, sum = 0;
    printf("Введите натуральное число n, количество элементов последовательности:\n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Введите элемент %d: ", i+1);
        scanf("%lf", &x);
        sum += x;
    }
    printf("Математическое ожидание последовательности: %f\n", sum/n);
}