#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int first(int x){
    return ++x;
    }
int second(int x){
    return ++x;
    }

int main(void){
    int a = first(1);
    int b = second(1);
    printf("%d %d \n", a, b);
    return 0;
}


