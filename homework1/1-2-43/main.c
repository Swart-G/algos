#include <math.h>
#include<stdio.h>

int main(){
    const double EPS = 1e-12;
    int sequence_len;
    int segment_len;
    int current_segment_len = 1;
    int segments_count = 0;
    int i = 1;
    double previous;
    double current;

    printf("Введите натуральное число n, минимальную длину искомых участков:\n");
    if (scanf("%d", &segment_len) != 1 || segment_len < 1) {
        printf("Некорректный ввод");
        return 1;
    }
    printf("Введите натуральное количество элементов последовательности:\n");
    if (scanf("%d", &sequence_len) != 1 || sequence_len < 1) {
        printf("Некорректный ввод");
        return 1;
    }
    printf("Введите элемент 1: ");
    if (scanf("%lf", &current) != 1) {
        printf("Некорректный ввод");
        return 1;
    }

    for (; i < sequence_len; i++) {
        previous = current;
        printf("Введите элемент %d: ", i+1);
        if (scanf("%lf", &current) != 1) {
            printf("Некорректный ввод");
            return 1;
        }

        if (fabs(current - previous) < EPS) {
            current_segment_len++;
        } else {
            if (current_segment_len >= segment_len) {
                segments_count++;
            }
            current_segment_len = 1;
        }
    }
    if (current_segment_len >= segment_len) {
        segments_count++;
    }

    printf("Количество постоянных участков в последовательности: %d\n", segments_count);
    return 0;
}