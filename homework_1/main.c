#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct fraction{
    long long num;
    long long den;
};

long long gcd(long long n1, long long n2){
    long long rem;
    while(n2 != 0){
        rem = n1 % n2;
        n1 = n2;
        n2 = rem;
    }
    return n1;
}
struct fraction toFraction(char str[]){
    long long i = 0;
    long long num = 0;
    long long den = 1;
    long long gcdN;
    bool isAfterDot = false;
    while(str[i] != '\0'){
        if(str[i] != '-' && str[i] != '.'){
            num = num * 10 + (str[i] - '0');
        }
        if(isAfterDot){
            den = den * 10;
        }
        if(str[i] == '.'){
            isAfterDot = true;
        }
        i++;
    }
    gcdN = gcd(num, den);
    num = num / gcdN;
    den = den / gcdN;
    if(str[0] == '-'){
        num = -1 * num;
    }
    struct fraction result = {num, den};
    return result;
}

long long lcm(long long a, long long b){
    return llabs(a) / gcd(a, b) * llabs(b);
}

long long findDivisors(long long n, long long divisors[]){
    n = llabs(n);
    long long count = 0;
    for(long long i = 1; i <= n; i++){
        if(n % i == 0){
            divisors[count] = i;
            count++;
        }
    }
    return count;
}

int main(){
    char strA[100];
    char strB[100];
    char strC[100];
    long long denLcm, coeffGcd, intA, intB, intC, countA, countC, p, q, value;
    long long divisorsA[100];
    long long divisorsC[100];
    struct fraction a, b, c;
    scanf("%s %s %s", strA, strB, strC);
    a = toFraction(strA);
    b = toFraction(strB);
    c = toFraction(strC);
    denLcm = lcm(lcm(a.den, b.den), c.den);
    intA = a.num*denLcm/a.den;
    intB = b.num*denLcm/b.den;
    intC = c.num*denLcm/c.den;

    if(intA == 0){
        if(intB == 0){
            if(intC == 0){
               printf("Бесконечное количество решений");
               return 0;
           }else{
               printf("Решений нет");
               return 0;
           }
        }else{
            printf("Корень: %lld / %lld", -intC, intB);
            return 0;
        }
    }

    coeffGcd = gcd(gcd(llabs(intA), llabs(intB)), llabs(intC));
    intA = intA/coeffGcd;
    intB = intB/coeffGcd;
    intC = intC/coeffGcd;
    if(intA < 0){
        intA = -intA;
        intB = -intB;
        intC = -intC;
    }

    if(intC == 0){
        printf("Корни: 0, %lld / %lld", -intB, intA);
        return 0;
    }

    countA = findDivisors(intA, divisorsA);
    countC = findDivisors(intC, divisorsC);

    for(long long i = 0; i < countC; i++){
        for(long long j = 0; j < countA; j++){
            p = divisorsC[i];
            q = divisorsA[j];

            value =
                (long long)intA * p * p +
                (long long)intB * p * q +
                (long long)intC * q * q;
            if(value == 0){
                printf("Корень: %lld / %lld\n", p, q);
            }
            p = -divisorsC[i];
            q = divisorsA[j];
            value =
                (long long)intA * p * p +
                (long long)intB * p * q +
                (long long)intC * q * q;
            if(value == 0){
                printf("Корень: %lld / %lld\n", p, q);
            }
        }
    }
    return 0;
}
