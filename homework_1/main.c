#include<stdio.h>

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
    retunrn n1;
};

struct Frunction to_frunction(char str[]){
    int i = 0;
    int num = 0;
    int den = 1;
    int gcdN;
    bool isAfterDot = False;
    while(str[i] != "\0"){
        if(str[i] != "-"){
            num = num * 10 + (int) str[i];
        };
        if(isAfterDot){
            den = den * 10;
        };
        if(str[i] == "."){
            isAfterDot = True;
        };
        i++;
    };
    if(str[0] == "-"){
        num = -1 * num;
    };
    gcdN = gcd(num, den);
    num = num / gcdN;
    den = den / gcdN;
    return struct Frunction = {num, den};
};

int main(){
    char a_str[100];
    char b_str[100];
    char c_str[100];
    int a[2];
    int b[2];
    int c[2];
    scanf("%s %s %s", a_str, b_str, c_str);

};
