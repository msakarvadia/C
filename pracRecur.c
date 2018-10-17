#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void print(int n);

int main(void){
    print(3);
    return 0;
}

void print(int n){
    if( n==0)
        return;
    print(n-1);
    for(int i = 0; i <n ; ++i)
        printf(" ");
    printf("****\n"); 
    }


