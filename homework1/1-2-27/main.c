#include <stdio.h>

int main() {
    int sequence_len;
    int first_min_element_index;
    int last_min_element_index;
    double min;
    double current;
    int i = 0;

    printf("Введите натуральное число n, количество элементов последовательности:\n");
    if (scanf("%d", &sequence_len) != 1 || sequence_len < 1) {
        printf("Некорректный ввод");
        return 1;
    }

    for (; i < sequence_len; i++) {
        printf("Введите элемент %d: ", i + 1);
        if (scanf("%lf", &current) != 1) {
            printf("Некорректный ввод");
            return 1;
        }

        if (i == 0) {
            min = current;
            first_min_element_index = i + 1;
            last_min_element_index = i + 1;
        } else if (current < min) {
            min = current;
            first_min_element_index = i + 1;
            last_min_element_index = i + 1;
        } else if (current == min) {
            last_min_element_index = i + 1;
        }
    }

    printf("Номер первого минимального числа последовательности: %d\n", first_min_element_index);
    printf("Номер последнего минимального числа последовательности: %d\n", last_min_element_index);
    return 0;
}
