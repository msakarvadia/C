#include <stdio.h>
#include <stdlib.h>


int main(void){
    int arr[] = {1,2,3,4};
    int *aptr = &arr[0];
    void *bptr = aptr;
    char* suit[] = {"diamonds", "clubs", "hearts", "spades"};
    char* suit2[] = {&suit[0], &suit[1], &suit[2], &suit[3]};


    printf("%p %p\n", arr+1, bptr);
    printf("%d %d\n", *(aptr+2), *(int*)bptr);
    printf("%zu\n", sizeof(suit[0]));     
    

    for(size_t i =0; i< sizeof(suit) / sizeof(suit[0]); ++i){
        puts(suit2[i]);    
        }


    return 0;
}


