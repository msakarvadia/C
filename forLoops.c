#include <stdio.h>

int main(Void){
    unsigned int counter=0;
    for(unsigned char i = 0, counter =0; i<10; ++i){
        printf("%u\n", counter++);
    }
    printf("%u\n", counter);
    for(;;)
        printf("%u\n", counter++)
    printf("%u\n", counter);
    
    return 0;
}
