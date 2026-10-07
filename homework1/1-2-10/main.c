#include <stdio.h>

int main() {
    int n, even_count = 0, odd_count = 0, x;
    printf("Введите натуральное число n, количество элементов последовательности:\n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Введите элемент %d: ", i+1);
        scanf("%lf", &x);
        if(x % 2 == 0){
            even_count += 1;
        } else{
            odd_count += 1;
        }
    }
    printf("Чётных чисел: %d\nНечётных чисел: %d\n", even_count, odd_count);
}