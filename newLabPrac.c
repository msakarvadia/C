#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

typedef struct name{
    char* first;
    char* middle;
    char* last;
    }Name;

void stars(unsigned int num);
void strSort(char* arr[],size_t size);
Name* namer(char* f, char* m, char* l);
char* nameStr(Name* namePtr);
int square(int n);
int superSum(int func(int), unsigned int n);

int main(void){
    stars(5);
    char* arr[] = {"h", "asdf", "a"};
    strSort(arr,3);
    for(int i = 0; i < 3; ++i){
        puts(arr[i]);
        }
    Name* name = namer("Mansi", "N", "Sak");
    puts(name->first);
    puts(name->middle);
    puts(name->last);
    char* out= nameStr(name);
    puts(out);
    printf("%d\n", superSum(square, 3));
    return 0;
}


void stars(unsigned int num){
    if (num == 1){
        printf("*\n");
    }
    else{
        for(unsigned int i = 0; i <num; ++i){
            printf("*");
        }
        puts("");
        stars(num-1);
        for(unsigned int i = 0; i <num; ++i){
            printf("*");
        }
        puts("");    

    }
}

void strSort(char* arr[],size_t size){
    char* temp;
    for(size_t i =0; i< size-1; ++i){
        for(size_t j =0; j< size-i-1; ++j){
            if(strcmp(arr[j],arr[j+1])>0){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                }
        }
    }
}

Name* namer(char* f, char* m, char* l){
    Name* out = malloc(sizeof(Name));
    out->first = malloc((strlen(f)+1)*sizeof(char));
    out->middle = malloc((strlen(m)+1)*sizeof(char));
    out->last = malloc((strlen(l)+1)*sizeof(char));
    strcpy(out->first, f);
    strcpy(out->middle, m);
    strcpy(out->last, l);
    return out;
}

char* nameStr(Name* namePtr){
    unsigned int space=0;
    if(namePtr->first != NULL){
        ++space;
    }
    if(namePtr->middle != NULL){
        ++space;
    }             
    if(namePtr->last != NULL){
        ++space;
    }             
    char* out = malloc((strlen(namePtr->first)+strlen(namePtr->middle)+ strlen(namePtr->last)+space)*sizeof(char));
    out[0]= 0;
    if(namePtr->first != NULL){
        strcat(out, namePtr->first);
        if(namePtr->middle != NULL || namePtr->last != NULL){
            strcat(out, " ");
        }
    }
    if(namePtr->middle != NULL){
        strcat(out, namePtr->middle);
        if(namePtr->last != NULL){
            strcat(out, " ");
        }
    }
    if(namePtr->last !=NULL){
        strcat(out, namePtr->last);
    }
    return out;

}

int square(int n){
    return n*n;
    }

int superSum(int func(int), unsigned int n){
    int total = 0;
    for(unsigned int i = 0; i<=n; ++i){
        total+= func(i);
        }
    return total;
    }
