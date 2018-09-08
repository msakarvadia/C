#include <stdio.h>

void printDimension(int arr[]);

int main(void){
    
    int b[3] = {1,2,3};
    printDimension(b);
    return 0;
}

void printDimension(int arr[]){
    printf("%zu\n", sizeof(arr));
    }

