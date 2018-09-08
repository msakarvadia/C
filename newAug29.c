#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE f

void modifyArray(int arr[], size_t size);
void modifyElement(int e);

int main(void){
  int a[] = {2,3,4,5,6};
  int b[] = a;

  b[0]=3;

    for(size_t i =0; i< SIZE; ++i) {printf("%3d\n", a[i]); }
    puts("")

/*    modifyArray(a, SIZE);
    for(size_t i =0; i< SIZE; ++i) {printf("%3d\n", a[i]); }
    modifyElement(a[0]);
    printf("%d\n", arr[0]);
*/  
  return 0;
}

void modifyArray(int arr[], size_t size);
{
    for (size_t i = 0; i< size; ++i){arr[i] *=2;}
    }

void modifyElement(int e);
{
        printf("%d\n", e*=2);
    }


