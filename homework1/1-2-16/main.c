#include <stdio.h>

int main()
{

    int sequence_len;
    int count = 0;
    int current;
    int i = 0;
    int last_element_index = -1;

    printf("Введите натуральное число n, количество элементов последовательности:\n");
    if (scanf("%d", &sequence_len) != 1 || sequence_len < 1) {
        printf("Некорректный ввод");
        return 1;
    }

    for (; i < sequence_len; i++) {
        printf("Введите элемент %d: ", i + 1);
        if (scanf("%d", &current) != 1) {
            printf("Некорректный ввод");
            return 1;
        }

        if (current % 5 == 0 && current % 1000 != current) {
            count += 1;
            last_element_index = i+1;
        }
    }

    printf("Количество подходящих элементов: %d\n", count);
    printf("Номер последнего подходящего элемента: %d\n", last_element_index);
    return 0;
}