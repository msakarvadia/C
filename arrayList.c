#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define INIT_CAPACITY 8
#define INIT_SIZE 

typedef struct arrayList {
    size_t capacity;
    size_t size;
    int* data;
}ArrayList;

ArrayList* create(void);
void cleer(ArrayList** arrListPtrPtr);
void insert(ArrayList* arrListsPtr, int val, size_t index);
bool delete(ArrayList* arrListPtr, int val);//deletes first instidance of val
void print(ArrayList* arrListPtr);
int get(ArrayList* arrListPtr, size_t index);
void append(ArrayList* arrListPtr, int val);
size_t find(ArrayList* arrListPtr, int val);  //first instance
bool isEmpty(ArrayList* arrListPtr);
void resizeIfNeeded(ArrayList* arrListPtr);
size_t binarySearch(int* data, size_t size, int val);
void set(ArrayList* arrListPtr, int val, size_t index);

int main(void){
    ArrayList* ptr = create();
    for(int i = 1; i<=10; ++i){
        append(ptr, i);
       }
    print(ptr);
    cleer(&ptr);
    print(ptr); 
    int a = get(ptr, 6);
    printf("%d\n", a);
    int b = get(ptr, 26);
    printf("%d\n",b);
    return 0;
}


ArrayList* create(void){
    ArrayList* new = malloc(sizeof(ArrayList));
    new->capacity = INIT_CAPACITY;
    new->size = 0;
    new->data = calloc(INIT_CAPACITY, sizeof(int));
    return new;
}

void print(ArrayList* arrListPtr){
    if(isEmpty(arrListPtr)){
        return;
        }
    for(size_t i = 0; i < arrListPtr->size; ++i){
        printf("%d ", arrListPtr->data[i]);
    }
    puts("");
}

void insert(ArrayList* arrListPtr, int val, size_t index){  //this is gonna make an unsorted list
    if(arrListPtr->size == arrListPtr->capacity){
        resizeIfNeeded(arrListPtr);
    }
    return;

}

void resizeIfNeeded(ArrayList* arrListPtr){
    if(arrListPtr->size == arrListPtr->capacity){
        arrListPtr->capacity *= 2;
        arrListPtr->data = realloc(arrListPtr->data, arrListPtr->capacity*sizeof(int));
    }
    return;
}

void append(ArrayList* arrListPtr, int val){
    resizeIfNeeded(arrListPtr);
    arrListPtr->data[arrListPtr->size++] = val;
    return;
}

bool isEmpty(ArrayList* arrListPtr){
    return arrListPtr == NULL || arrListPtr->size == 0;
    }

void cleer(ArrayList** arrListPtrPtr){
    free((*arrListPtrPtr)->data);
    free(*arrListPtrPtr);
    *arrListPtrPtr = NULL;
    
    }

int get(ArrayList* arrListPtr, size_t index){
    if(arrListPtr->size <= index){
        fprintf(stderr,"Index out of bounds\n" );
        return 0; 
        }

    return arrListPtr->data[index];
    }

size_t find(ArrayList* arrListPtr, int val){
    for(size_t i = 0; i<arrListPtr->size; ++i){
        if(arrListPtr->data[i]==val){
            return i;
        }

    }
    fprintf(stderr, "Value *d not found\n", val);
    return (size_t)-1;
}

void set(ArrayList* arrListPtr, int val, size_t index){
    if((arrListPtr->size)+1 > index){
        arrListPtr-data[index] = val;
    }
    append(arrListPtr, 0);
    set(arrListPtr, val, index);

}

/*
   size_t binarySearch(int* data, size_t size, int val){
   size_t middle = size/2;
   if(size==0){
   return 0;
   }
   if(data[middle]==val){
   return middle;
   }
   if(data[middle]>val){
   binarySearch(data,middle, )
   }
   } */
