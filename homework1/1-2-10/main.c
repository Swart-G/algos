#include <stdio.h>

int main()
{
    int count;
    int even_count = 0;
    int odd_count = 0;
    int current;
    int i = 0;
    printf("Введите натуральное число n, количество элементов последовательности:\n");
    if (scanf("%d", &count) != 1 || count < 1) {
        printf("Некорректный ввод");
        return 1;
    }
    for (; i < count; i++) {
        printf("Введите элемент %d: ", i + 1);
        if (scanf("%d", &current) != 1) {
            printf("Некорректный ввод");
            return 1;
        }
        if (current % 2 == 0) {
            even_count += 1;
        } else {
            odd_count += 1;
        }
    }
    printf("Чётных чисел: %d\nНечётных чисел: %d\n", even_count, odd_count);
    return 0;
}