#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

 typedef struct name{
    const char* f;
    const char* m;
    const char* l;
    } Name;
 
    
    Name *fullName;

void starPrint(int n);
char* sorter(char* strArr);
Name* namer(char* first, char* middle, char* last);
//char* namePrint(Name* fullName);
int square(int x){
    return x*x;
    }
int doubler(int x){
    return x*2;
    }
int sum(int square(int), int n);


int main(void){
    starPrint(3);
//    char * test = {"a", "c", "b"};
    //printf("%s\n", sorter(test));
    namer("Mansi", "N", "Sak");
    printf("%s, %s, %s\n", fullName ->f, fullName ->m, fullName ->l);
    printf("%d\n", sum(square, 3));
    printf("%d\n", sum(doubler, 3));
    return 0;
}

 void starPrint(int n){
    if(n==0){
        return;
        } 
   for(int i= n; i>0; i--){
        printf("*");
        } 
    printf("\n");
    starPrint(n-1);
    for(int i = 0; i<n; i++){
        printf("*");
        }
    printf("\n");
    }

 int sum(int func(int), int n){
    if(n == 0){
        return 0;
        }
    else{
        return func(n)+sum(func, n-1);
        }
}
/*char* sorter(char* strArr){
    int x,y;
    int len = sizeof(strArr)/sizeof(strArr[0]);
        for (x =0, x<len; x++){
            for(y = x +1; y<len; y++){
                if((strcmp(strArr[x], strArr[y]))>0){
                    char* temp = strArr[x];
                    strArr[x] = strArr[y];
                    strArr[y] = temp;
                }
            }
        }
        return strArr;
} */


Name* namer(char* first, char* middle, char* last){
    fullName = (Name *)malloc(sizeof(Name));
    fullName -> f = first;
    fullName -> m = middle;
    fullName -> l = last;
    return fullName;
    }
/*
char* namePrint(Name* fullName){
    int first = sizeof(fullName ->f);
    int mid = sizeof(fullName -> m);
    int last = sizeof(fullName -> l);
    char* full = malloc(first+mid+last+1);
    char* F = fullName -> f;
    char* M = fullName -> m;
    char* L = fullName -> l;
    if(m == 0){
      for(int i =0 ; i<first, i++){
          full[i] = F[i];
          }
      full[first] = " ";
      for (int i = first+1; i<last; i++){
          full[i]= L[i];
          }

    }
    
    
    }*/




