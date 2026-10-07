#include<stdio.h>

int main(){

    int sequence_len;
    int count;
    int current;
    int i = 0;
    int first_element_index = -1;

    printf("Введите натуральное число n, количество элементов последовательности:\n");
    scanf("%d", &sequence_len);

    for(i; i < sequence_len; i++){
        printf("Введите элемент %d: ", i+1);
        scanf("%d", &current);

        if(current % 5 == 0 && current % 1000 != current){
            count += 1;
            if(first_element_index == -1){
                first_element_index = i+1;
            }
        }
    }

    printf("Количество подходящих элементов: %d\n", count);
    printf("Номер первого подходящего элемента: %d\n", first_element_index);
    return 0;
}