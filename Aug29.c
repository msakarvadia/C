#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
//    int x[] ;
    int y[5];
//    y = {3,4,5,6,7};
    printf("Size of y: %zu\n", sizeof(y)/sizeof(y[0]));    
 //   printf("Size of x: %zu\n", sizeof(x)/sizeof(x[0]));    
    for (size_t i=0; i< sizeof(y)/sizeof(y[0]); ++i)
        printf("%d\n", y[i]);

    char a[3]= "Hello";
    printf("%s\n", a);
    printf("%zu\n", strlen(a));
    for (size_t i=0; i< sizeof(a)/sizeof(a[0]); ++i)
        printf("%d\n", a[i]);     
}

