#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct example{
    char c;
    }Example;

typedef Example* ExamplePtr;


ExamplePtr  fun(char c);

int main(void){
    ExamplePtr exPtr = fun('m');
    printf("%c\n", exPtr->c);
    return 0;
}

ExamplePtr fun(char c){
    ExamplePtr exPtr = malloc(sizeof(Example));
    exPtr -> c = c;
    return exPtr;
    }

