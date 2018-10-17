#include <stdio.h>

typedef struct card {
    char *face;
    char *suit
    } Card;

int main(void){
    struct exaple {
        char c;
        int i;
        } x, y;
    x.c = 'a';
    x.i = 54;
    printf("%c %d\n", x.c, x.i);
    Card aCard, deck[52], *cardPtr;
    aCard.face =  "Ace";
    aCard.suit = "Spades";
    cardPtr = &aCard;
    printf("%s %s \n", aCard.face, aCard.suit);
    printf("%s %s \n", cardPtr->face, cardPtr->suit);
    printf("%s %s\n", (*cardPtr).face, (*cardPtr).suit);
    return 0;
}


