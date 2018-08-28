#include <stdio.h>

int main(Void){
    unsigned int counter=0;
    for(unsigned char i = 0, counter =0; i<10; ++i){
        printf("%u\n", counter++);
    }
    printf("%u\n", counter);
    for(;;)
        printf("%u\n", counter++);
    printf("%u\n", counter);    //this is a useless line because the prvious loop is infinite and will ultimately need to be interupted with crtl c
    
    return 0;
}
