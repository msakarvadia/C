//BY: Mansi Sakarvadia
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ITER 1000

//THIS IS A GAME OF CRAPS

enum Status {LOST, CONTINUE, WON};
int lostCounter = 0;
float gameLengthCounter;
int wonCounter = 0;
float lengthSum = 0;
float Zeroto5LenCount = 0;
float VIto10LenCount = 0;
float XIto20LenCount = 0;
float XXIto50LenCount = 0;
float LPlusLenCount = 0;
float Zeroto5LenLossCount = 0;
float VIto10LenLossCount = 0;
float XIto20LenLossCount = 0;
float XXIto50LenLossCount = 0;
float LPlusLenLossCount = 0;
 
unsigned char rollDice(void);

int main(void){
    srand(time(NULL));
    unsigned char point;
    enum Status gameStatus;
    gameLengthCounter = 0;
    for(int i = 0; i<ITER; i++){
        unsigned char sum = rollDice();           
        switch(sum){
            case 7:
            case 11:
                gameStatus = WON;
                wonCounter ++;
                gameLengthCounter=1;
                Zeroto5LenCount ++;
                break;
            case 2:
            case 3:
            case 12:
                gameStatus = LOST;
                lostCounter ++;
                gameLengthCounter=1;
                Zeroto5LenLossCount ++;
                break;
            default:             
                gameLengthCounter ++;
                gameStatus = CONTINUE;
                point = sum;
        }
        while(gameStatus == CONTINUE){
            sum = rollDice();
            if (sum == point){
                gameStatus = WON;
                wonCounter ++;
                gameLengthCounter ++;
                if(gameLengthCounter<6){     
                    Zeroto5LenCount ++;
                    break;
                }
                else if(gameLengthCounter<11){
                    VIto10LenCount ++;
                    break;
                }
                else if(gameLengthCounter<21){
                    XIto20LenCount ++;
                    break;
                }
                else if(gameLengthCounter<50){
                    XXIto50LenCount ++;
                    break;
                }
                else if(gameLengthCounter>=50){
                    LPlusLenCount ++;
                    break;
                }
            }
            else if(sum == 7){
                gameStatus = LOST;
                lostCounter ++;
                gameLengthCounter ++;
                if(gameLengthCounter<6){     
                    Zeroto5LenLossCount ++;
                    break;
                }
                else if(gameLengthCounter<11){
                    VIto10LenLossCount ++;
                    break;
                }
                else if(gameLengthCounter<21){
                    XIto20LenLossCount ++;
                    break;
                }
                else if(gameLengthCounter<50){
                    XXIto50LenLossCount ++;
                    break;
                }
                else if(gameLengthCounter>=50){
                    LPlusLenLossCount ++;
                    break;
                }            
            }
            else{
                gameLengthCounter++;    
            }

        }
        //       printf("game number: %d game Status: %d, game length: %f\n", i, gameStatus, gameLengthCounter);
        lengthSum += gameLengthCounter;

    }
    printf("# won: %d, # lost: %d\n", wonCounter, lostCounter);
    float winChance =   (float)wonCounter/(float)(wonCounter+lostCounter);
    printf("chances of winning: %0.2f\n",winChance);
    printf("average length of game: %0.2f\n",lengthSum/ITER);
    printf("Games won in:\n 0-5 moves: %f games\n 6-10 moves: %f games\n 11-20 moves: %f games\n 21-50 moves: %f games\n 50+ moves: %f games\n", Zeroto5LenCount, VIto10LenCount, XIto20LenCount, XXIto50LenCount, LPlusLenCount);
    printf("Games lost in:\n 0-5 moves: %f games\n 6-10 moves: %f games\n 11-20 moves: %f games\n 21-50 moves: %f games\n 50+ moves: %f games\n", Zeroto5LenLossCount, VIto10LenLossCount, XIto20LenLossCount, XXIto50LenLossCount, LPlusLenLossCount);
    printf("The above data usually supports the conjecture that the greater the length of the game, the lower the chances of winning.\n");
    return 0;         
}

unsigned char rollDice(void){
    return rand() % 6 +1 + rand() % 6 + 1;
}
