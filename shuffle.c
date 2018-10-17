#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define CARDS 52
#define FACES 13


typedef struct card{
    const char* face;
    const char* suit;
    } Card;

void fillDeck(Card* const deck, const char* faces[], const char* suits[]);
void shuffle(Card* const deck);
void deal(const Card * const deck);

int main(void){
    srand(time(NULL));
    const char* faces[] = {"Deuce","Tres","Boat","Nickel","Sax", "Salmon","Snowman","Niner", "Dime", "Lancelot","Athena", "Ceasar", "Rocket" };
    const char* suits[] = {"Diamonds", "Clubs", "Hearts", "Spades"};
    Card deck[CARDS];
    fillDeck(deck, faces, suits);
    deal(deck);
    puts("----"); 
    shuffle(deck);
    deal(deck);
    return 0;
}


void fillDeck(Card deck[], const char* faces[], const char* suits[]){
    for(size_t i = 0; i<CARDS; ++i){
        deck[i].face = faces[i%FACES];
        deck[i].suit = suits[i%4];
        }
    }

void shuffle(Card* const deck){
    Card temp;
    for(size_t i=51; i>0; --i){
        int r = rand()%i;
        temp = deck[i];
        deck[i]=deck[r];
        deck[r] = temp;
        }
    }

void deal(const Card * const deck){
     for(size_t i =0; i<CARDS; ++i){
        printf("%s of %s\n", deck[i].face, deck[i].suit);
        }  
    }
