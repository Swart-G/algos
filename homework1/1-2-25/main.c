#include <stdio.h>

int main()
{
    int sequence_len;
    int first_max_element_index;
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
            max = current;
            first_max_element_index = i + 1;
        } else {
            if (current > max) {
                max = current;
                first_max_element_index = i + 1;
            }
        }
    }

    printf("Номер первого максимального числа последовательности: %d\n", first_max_element_index);
    return 0;
}