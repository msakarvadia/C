#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));  //not a useful line for this funciton
    int random;
    while(true){
        printf("enter grade here:");
        scanf("%d", &random);
        if( random == 10){
            printf("A-\n");
        }
        else if(random>= 90){
            printf("B\n");
        }
        else if(random >=80){
            printf("c\n");
        }
        else{
            printf("f\n");
        }
    }
    printf("%d\n", random);
    return 0;
}
