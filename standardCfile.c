#include <stdio.h>

void fun(void);
unsigned int count = 10;

int main(void){
    
    while (count>0){
        fun();
    }

    int arr[5];
    for(size_t i = 0; i<5; i++){
        printf("%d, " arr[i])
    }
    puts("");
    return(0);

}

void fun(void){
    static unsigned int i = 0;
    printf("%u %u\n", count--, i++);
    }
