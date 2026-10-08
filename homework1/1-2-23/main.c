#include <stdio.h>
#include <math.h>

int main()
{
    int sequence_len;
    double x_num;
    double current;
    int i = 0;
    int last_equal_element_index = -1;
    const double EPS = 1e-12;

    printf("Введите число X:\n");
    if (scanf("%lf", &x_num) != 1) {
        printf("Некорректный ввод");
        return 1;
    }

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

        if (fabs(current - x_num) < EPS) {
            last_equal_element_index = i + 1;
        }
    }

    printf("Номер последнего элемента последовательности, равного числу X: %d\n", last_equal_element_index);
    return 0;
}