//By: Mansi Sakarvadia
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

int binarySearch(int arr[], size_t start, size_t end, int key);
void fillArray(int arr[], size_t size);

int arr[SIZE];
int testArr[10] = {4, 182, 1094, 582 ,2000, 37, 359, 487, 765,91};
int main(void){
    int ret;
    fillArray(arr, SIZE);
    for(unsigned int i = 0; i < sizeof(testArr)/sizeof(testArr[0]); i++){
        ret = binarySearch(arr, 0, SIZE, testArr[i]) ;
        printf("The search for key %d returned index: %d\n",testArr[i], ret);
    }
    return 0;
}


int binarySearch(int arr[], size_t start, size_t end, int key){
    if(arr[start] == key){
        return start;
    }
    if(start >= end){
        return -1;
    }
    return(binarySearch(arr, start+1, SIZE, key));
}

void fillArray(int arr[], size_t size){
    for(unsigned int i=0; i<(size+1); i++) {
        arr[i] = i*2;    
    }
}
