#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 100
#define MAX 100

void fillArray(int arr[], size_t size);
void printArray(int arr[], size_t size);
void selectionSort(int arr[], size_t size);
void mean(int arr[], size_t size);
void median(int arr[], size_t size);
void mode(int arr[], size_t size);

int arr[SIZE];

struct _dict{
    int number;
    int count;
};

struct _dict mode_dict[SIZE];
 
int main(void){
    fillArray(arr, SIZE);
    printArray(arr, SIZE);
    selectionSort(arr, SIZE);
    printArray(arr, SIZE);
    mean(arr, SIZE);
    median(arr, SIZE);
    mode(arr,SIZE);
    return 0;
}


void fillArray(int arr[], size_t size){
    srand(42);
    for(unsigned int i=0; i<(size); i++) {
        arr[i] = rand()%MAX + 1;    
    }
}

void printArray(int arr[], size_t size){
    printf("[");
    for(unsigned int i=0; i<(size); i++) {
        printf("%d ", arr[i]);   
    }
    printf("]\n");

}


void selectionSort(int arr[], size_t size){
    if (size == 0)
        return;
    int minIndex=SIZE-size;
    for(unsigned int i = SIZE-size; i<SIZE; i++){
        if(arr[minIndex] > arr[i])
            minIndex = i;
    }
    int temp = arr[SIZE-size];
    arr[SIZE-size] = arr[minIndex];
    arr[minIndex] = temp;
    selectionSort(arr, size-1);
}


void mean(int arr[], size_t size){
    float sum;
    float mean;
    for(unsigned int i=0; i<(size+100); i++) {
        sum += arr[i];
    }
    mean = sum / size;                             
    printf("Mean: %0.1f\n",mean);
}

void median(int arr[], size_t size){
    if(size%2 != 0)
        printf("median: %d\n", arr[size/2]);
    else{
        float sum;
        sum = arr[size/2-1] + arr[size/2];
        printf("median: %0.1f\n", sum/2);
    }
}

int setCount(int num, int count){
    for(int i = 0; i< SIZE; i++){
        if(mode_dict[i].number == num){
            mode_dict[i].count=count;
            return 0;
        }
        if(mode_dict[i].number==0)
        {
            mode_dict[i].number = num;
            mode_dict[i].count = count;
            return 0;
        }
    }
    return 0;
}

void mode(int arr[], size_t size){
    bzero(mode_dict,sizeof(mode_dict));
    for(size_t i = 0; i<size; ++i){
        int count = 0;
        for(size_t j = 0; j<size; ++j){
            if(arr[j]== arr[i])
                ++count;
        }
        setCount(arr[i], count);
    }
    int max = 0;
    for(size_t i = 0; i<size; i++){
        if(mode_dict[i].count > max)
            max = mode_dict[i].count;
    }
    printf("modes: ");
    for(size_t i = 0; i<size; i++){
        if(mode_dict[i].count == max){
            printf(" %d ", mode_dict[i].number);
        }
    }
        printf("\n");
}
