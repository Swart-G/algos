#include<stdio.h>

int main(){
    int sequence_len;
    int first_min_element_index;
    double min;
    double current;
    int i = 0;

    printf("Введите натуральное число n, количество элементов последовательности:\n");
    scanf("%d", &sequence_len);

    for(i; i < sequence_len; i++){
        printf("Введите элемент %d: ", i+1);
        scanf("%lf", &current);

        if(i == 0){
            min = current;
            first_min_element_index = i+1;
        } else{
            if(current < min){
                min = current;
                first_min_element_index = i+1;
            }
        }
    }

    printf("Номер первого минимального числа последовательности: %d\n", first_min_element_index);
    return 0;
}