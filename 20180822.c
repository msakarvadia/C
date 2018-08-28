#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
/*
int main(void)
{
    srand(time(NULL));
    int random;
    for(unsigned char i =0; i<10; ++i){
    scanf("%d", &random);
    if( random == 10){
        printf("A-\n");
    } else if(random>= 90){
        printf("B\n");
    } else if(random >=80){
        printf("c");
    } else{
        printf("f");
    }
    }
    printf("%p\n", &random);
    return 0;
}
*/

int main(void){
    puts("spaghetti"); //automatically prints out a new line char
    unsigned int ternary = 5>4? 35:99;
    int x = 5<4? 3: 3<5? 1:2;
    printf("%d %d\n", ternary, x);
    char grade;
    unsigned int acount=0, bcount=0, ccount=0, dcount=0, fcount=0;
    while ((grade = getchar())!= EOF){
        switch (grade){
            case 'A':
            case 'a':
                ++acount;
                break;
            case 'B':
            case 'b':
                ++bcount;
                break;
            case 'C':
            case 'c':
                ++ccount;
                break;
            case 'F':
            case 'f':
                ++fcount;
                break;
            case '\n':
                break;
            default:
                puts("enter a working grade");
        }

    }
    printf("%d, %d, %d, %d, %d", acount, bcount, ccount, dcount, fcount);
    

    return 0;
}
