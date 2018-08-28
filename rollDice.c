#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6
#define ROLLS 100

int main(void){
    srand(time(NULL));

    unsigned int freq[SIZE] = {0};
    
    for(unsigned int i = 0; i<ROLLS; ++i){
        ++freq[rand()%SIZE];    
        }
    for(size_t i = 0; i<SIZE; ++i){
        
        printf("%4zu%17d\n", i+1, freq[i]);
        }
    return 0;
    }
