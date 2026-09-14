#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct Frunction{
    int num;
    int den;
};

int gcd(int n1, int n2){
    int rem;
    while(n2 != 0){
        rem = n1 % n2;
        n1 = n2;
        n2 = rem;
    };
    return n1;
};
struct Frunction to_frunction(char str[]){
    int i = 0;
    int num = 0;
    int den = 1;
    int gcdN;
    bool isAfterDot = false;
    while(str[i] != '\0'){
        if(str[i] != '-' && str[i] != '.'){
            num = num * 10 + (str[i] - '0');
        };
        if(isAfterDot){
            den = den * 10;
        };
        if(str[i] == '.'){
            isAfterDot = true;
        };
        i++;
    };
    gcdN = gcd(num, den);
    num = num / gcdN;
    den = den / gcdN;
    if(str[0] == '-'){
        num = -1 * num;
    };
    struct Frunction result = {num, den};
    return result;
};

int lcm(int a, int b){
    return abs(a) / gcd(a, b) * abs(b);
};

int main(){
    char strA[100];
    char strB[100];
    char strC[100];
    int k, intA, intB, intC;
    struct Frunction a, b, c;
    scanf("%s", strA);
    scanf("%s", strB);
    scanf("%s", strC);
    a = to_frunction(strA);
    b = to_frunction(strB);
    c = to_frunction(strC);

    k = lcm(lcm(a.den, b.den), c.den);
    intA = a.num*k/a.den;
    intB = b.num*k/b.den;
    intC = c.num*k/c.den;
    printf("%d\n", k);
    printf("%d %d %d\n", intA, intB, intC);    
};
