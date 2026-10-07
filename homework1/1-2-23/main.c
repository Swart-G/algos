#include<stdio.h>

int main(){
    int sequence_len;
    double x_num;
    double current;
    int i = 0;
    int last_equal_element_index = -1;

    printf("Введите число X:\n");
    scanf("%lf", &x_num);

    printf("Введите натуральное число n, количество элементов последовательности:\n");
    scanf("%d", &sequence_len);

    for(i; i < sequence_len; i++){
        printf("Введите элемент %d: ", i+1);
        scanf("%lf", &current);

        if(current == x_num){
            last_equal_element_index = i+1;
        }
    }

    printf("Номер последнего элемента последовательности, равного числу X: %d\n", last_equal_element_index);
    return 0;
}