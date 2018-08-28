#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//THIS IS A GAME OF CRAPS

enum Status {LOST, CONTINUE, WON};

unsigned char rollDice(void);

int main(void){
    srand(time(NULL));
    unsigned char point;
    unsigned char sum = rollDice();           
    enum Status gameStatus;
    switch(sum){
        case 7:
        case 11:
            gameStatus = WON;
        case 2:
        case 3:
        case 12:
            gameStatus = LOST;
            break;
        default:
            gameStatus = CONTINUE;
            point = sum;
    }
    while(gameStatus == CONTINUE){
        sum = rollDice();
        if (sum == point)
           gameStatus = WON;
        else if(sum == 7)
            gameStatus = LOST;
    }
    printf("%d\n", gameStatus);
    printf("%d %d %d \n", LOST, CONTINUE, WON);
    return 0;         
}

unsigned char rollDice(void){
    return rand() % 6 +1 + rand() % 6 + 1;
}
