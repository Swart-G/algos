#include<stdio.h>

int main(){
    int sequence_len;
    double min;
    double max;
    double current;
    int i = 0;

    printf("Введите натуральное число n, количество элементов последовательности:\n");
    scanf("%d", &sequence_len);

    for(i; i < sequence_len; i++){
        printf("Введите элемент %d: ", i+1);
        scanf("%lf", &current);

        if(i == 0){
            min = current;
            max = current;
        } else{
            if(current < min){
                min = current;
            }
            if(current > max){
                max = current;
            }
        }
    }

    printf("Максимальный член последовательности: %lf\n", max);
    printf("Минимальный член последовательности: %lf\n", min);
    return 0;
}