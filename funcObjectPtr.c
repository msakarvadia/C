#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 10
#define RANGE 42

void printArray(int arr[], size_t size);
bool ascending(int a, int b);
bool descending(int a, int b);
void bubbled(int arr[], size_t size, bool (compare)(int a, int b));
void swap(int *a, int *b);

int main(void){
    srand(time(NULL));
    int arr[SIZE];
    for(size_t i=0; i <SIZE; ++i){
        arr[i] = rand() % RANGE +1;
        }
        bubble(arr, SIZE, ascending);
        printArr(arr, SIZE);
        bubble(arr, SIZE, descending);
        printArr(arr, SIZE);
    return 0;
}


void printArray(int arr[], size_t i){
    for(size_t i=0; i <SIZE; ++i){
        printf("%d ", arr[i]);
    }
    puts("");
}       

bool ascending(int a, int b){
    return b<a;
    }  
    
    
bool descending(int a, int b){
    return a<b;
} 


void bubbled(int arr[], size_t size, bool (*compare)(int a, int b)){
    for(unsigned int pass =1; pass<size; ++pass){
        for(size_t count = 0; count< size-pass; ++count){
           if((compare)(arr[count], arr[count+1])){
               swap(arr+count, arr+count+1);
               }
           }
        }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    }
