#include <stdio.h>


int main(void){
    const int x = 2;
    const int* y = &x;
    y ++;
    printf("%d\n", x);
    return 0;
}


