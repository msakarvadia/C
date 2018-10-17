#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define SIZE 6

void coin(unsigned int flips);
int dice(unsigned int dice); 
int palindrome(char* string);
bool startEndCheck(char* string, int s, int e);
int baseChecker(char* string);
char* caesar(char* cipher, int shift);

//class functions
int fun1(int n); //coin flipper
int fun2(int n); //dice
int fun3(char* input);

char* result;

int main(void){
   coin(100);
   printf("%d\n", fun1(100));
   printf("With %d dice, you need %d Rolls to get yatzi.\n",10, dice(10)); 
   printf("With %d dice, you need %d Rolls to get yatzi.\n",10, fun2(10)); 
   printf("Is 'tat' a palindrome (1 for true, 0 for false):%d\n", palindrome("tat"));
   printf("Is 'tat' a palindrome (1 for true, 0 for false):%d\n", fun3("tat"));
   printf("This is the lowest possible base of 'X5Z': %d\n", baseChecker("X5Z"));
   printf("%s\n",caesar("mansi", 13));
   free(result);
   return 0;
    }   

int fun1(int n){
    srand(42);
    int counter = 0;
    for (int i =0; i<n; ++i){
        counter += rand()%2;
        }                   
    return n-counter;
    }

void coin(unsigned int flips){
    srand(42);

    unsigned int freq[2] = {0};

    for(unsigned int i = 0; i<flips; ++i){
       ++freq[rand()%2];    
    }
    printf("Zeros rolled: %d\n", freq[0]);
}

int dice(unsigned int dice){ 
    srand(42);
    int rolls = 0;
    for(;;){
        unsigned int face[6]={0};
        for(unsigned int i = 0; i<dice ; ++i){
            face[rand()%SIZE] += 1;
        } 
        rolls += 1;                                                     
        for(unsigned int i=0; i<SIZE; ++i){
            if(face[i]==dice){
                return rolls;
            }

        }
    }
    return 0;
}

//class version of above code
int fun2(int n){
    srand(42);
    int num = 1;
    int counter = 1;
    while (num<n){
        int previous = rand()%6;
        for(int i = 0; i<n-1; ++i){
            int current = rand()%6;
            if (current == previous) {
                num++;
            }
            else{
                num = 1;
                break;
            }

        }
        counter++;
    }
    return counter;
}


bool startEndCheck(char* string, int s, int e){
    if (s == e)
        return true;
    if (string[s]!=string[e])
        return false;
    if (s<e+1)
        return startEndCheck(string, s+1,e-1);
    return false;
}

int palindrome(char* string){
    int n = strlen(string);
    if(n==0)
        return true;
    return startEndCheck(string, 0, n-1);
}                     
 
 int fun3(char* input){
    if (strlen(input)<=1){
        return true;
    }
    if (input[0]==input[strlen(input)-1]){
        char arr[strlen(input)-2];
        memcpy(arr, input-1, strlen(input)-2);
        arr[strlen(input)-1] = '\0';
        return fun3(arr);
        }
        return false;
    }
 
int baseChecker(char* string){
    int n = strlen(string);
    int largest = 0;
    for(int i = 0; i<n; ++i){
        if(largest<string[i]){
            largest = string[i];
        }
    }
    if(largest==48||largest==49){
        return 2;
        }
    for(int j=90; j>=65; --j){
        if(largest==j){
            return (j-65)+11;
        }
    }
    for(int i=57; i>=48; --i){
        if(largest==i){
            return (i-47);
        }

    }                             
    return 0;

}

char* caesar(char* cipher, int shift){
    int n = strlen(cipher);
    result = malloc(n+1);
    for(int i =0; i<n; ++i){
        result[i] = 65 + (cipher[i]-97+shift)%26;
        }              
    result[n] = '\0';
    return result;
    }
