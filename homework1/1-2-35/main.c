#include<stdio.h>
#include<stdbool.h>

int main(){
    int sequence_len;
    bool is_arithmetic_sequence = true;
    double previous;
    double current;
    int i = 2;
    double diff;

    printf("Введите натуральное число n, количество элементов последовательности:\n");
    if (scanf("%d", &sequence_len) == 0 || sequence_len < 1) {
        printf("Некорректный ввод");
        return 1;
    }

    if (sequence_len == 1) {
        printf("Последовательность является арифметической прогрессией");
        return 0;
    }

    printf("Введите элемент 1: ");
    if (scanf("%lf", &previous) == 0) {
        printf("Некорректный ввод");
        return 1;
    }
    printf("Введите элемент 2: ");
    if (scanf("%lf", &current) == 0) {
        printf("Некорректный ввод");
        return 1;
    }
    diff = current - previous;

    for (i; i < sequence_len; i++) {
        previous = current;
        printf("Введите элемент %d: ", i+1);
        if (scanf("%lf", &current) == 0) {
            printf("Некорректный ввод");
            return 1;
        }

        if (current - previous != diff) {
            is_arithmetic_sequence = false;
        }
    }

    if (is_arithmetic_sequence) {
        printf("Последовательность является арифметической прогрессией");
    } else {
        printf("Последовательность НЕ является арифметической прогрессией");
    }
    return 0;
}