#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void starPrint(int n);


int main(void){
    
    starPrint(3);
    return 0;
}


void starPrint(int n){
    if(n==0){
        return;
        }
    starPrint(n-1);
    for(int i = 0; i<n; i++){
        printf(" ");
        }
    printf("****\n");
    }
