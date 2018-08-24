#include <stdio.h>
#define favNum 4

int square(int y);
unsigned int factorial(unsigned int n);

int main(void){
    int a, b, c;
    a = favNum*(b = 21);
    printf("%d\n", a);
    c = square(a);
    printf("%d\n", c);
    printf("%u\n", factorial(1));
    return 0;
}

int square(int y){
    return y*y;
}

unsigned int factorial(unsigned int n){
    if(n==0)
        return 1;
    return n*factorial(n-1);
}

