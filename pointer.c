#include <stdio.h>

int cubeByValue(int x);
void cubeByReference(int *xptr);


int main(void){
    int x = 83;
    int *xptr;
    xptr = &x;
    printf("%d\n %p\n", x, xptr );
    cubeByValue(x);
    printf("%d\n", x);
    cubeByReference(x);
    printf("%d\n", x);

    return 0;
    }
    

int cubeByValue(int x){
    return x*x*x;
    }


void cubeByReference(int *xptr){
    *xptr = *xptr * *xptr * *xptr;

    }

