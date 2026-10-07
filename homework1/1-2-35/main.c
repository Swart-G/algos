#include<stdio.h>
#include<stdbool.h>

int main(){
    int sequence_len;
    bool is_arithmetic_sequence;
    double previous;
    double current;
    double first_min_element_index;
    int i = 1;

    printf("Введите натуральное число n больше 1, количество элементов последовательности:\n");
    scanf("%d", &sequence_len);

    printf("Введите элемент 1: ");
    scanf("%lf", &previous);

    for(i; i < sequence_len; i++){
        printf("Введите элемент %d: ", i+1);
        scanf("%lf", &current);

    }


    return 0;
}