#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
	int a, b, c, n, k, x1, x2;
	printf("Введите коэфиценты уравнения в формате: A B C. Например, 1 -5 6.\n");
	scanf("%d %d %d", &a, &b, &c);
	
	if(a==0){
		printf("Квадратное уравнение некорректно!");
		return 0;
	};
	if(b==0){
		if(a*c>0){
			printf("Уравненние не имеет действительных корней");
			return 0;
		};
		printf("Решения уравнения - %f, %f", -1*sqrt((-1*c/a)), sqrt((-1*c/a)));
		return 0;
	};
	if(c==0){
		printf("Решения уравнения - 0, %d", -1*b/a);
		return 0;
	};

	n = c/a;
	k = b/a;
	for(int i=1; i <= sqrt(abs(n)); i++){
		if(n % i == 0){
			x1 = i;
			x2 = abs(n)/x1;
			if(n>0){
				if(x1 + x2 == -1*k){
					printf("Корни уравнения - %d, %d", x1, x2);
					return 0;
				};
				if(-1*x1 + -1*x2 == -1*k){
					printf("Корни уравнения - %d, %d", -1*x1, -1*x2);
					return 0;
				};
			} else{
				if(x1 + -1*x2 == -1*k){
					printf("Корни уравнения - %d, %d", x1, -1*x2);
					return 0;
				};
				if(-1*x1 + x2 == -1*k){
					printf("Корни уравнения - %d, %d", -1*x1, x2);
					return 0;
				};

			};
		};
	};
	printf("Целых корней не найдено(");
	return 0;
}
