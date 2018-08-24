#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int random;
    while(true){
    scanf("%d", &random);
    if( random == 10){
        printf("A-");
    }
    else if(random>= 90){
        printf("B");
    }
    else if(random >=80){
        printf("c");
    }
    else{
        printf("c");
    }
    }
    printf("%x\n", &random);
    return 0;
}
