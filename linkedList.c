#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct listNode{
    char datum;
    struct listNode* next;
    }ListNode;

typedef ListNode* ListNodePtr;

void insert(ListNodePtr* listPtr, char value);
void delete(ListNodePtr* listPtr, char value);
void print(ListNodePtr list);
void clearList(ListNodePtr* listPtr);
bool isEmpty(ListNodePtr list);
char get(ListNodePtr list, size_t index);

int main(void){
    printf("%d \n", (char)-1);
    ListNodePtr list = NULL;
    printf("%f\n", isEmpty(list));
    insert(&list, 'k');
    insert(&list, 'q');
    insert(&list, 'f');
    insert(&list, 'j');
    printf("%f\n", isEmpty(list));
    printf("%d \n", get(list, 0));
    printf("%d \n", get(list, 1));
    printf("%d \n", get(list, 2));
    printf("%d \n", get(list, 3));
    printf("%d \n", get(list, 4));
    print(list);
    delete(&list, 'k');
    print(list);
    delete(&list, 'q');
    print(list);
    delete(&list, 'f');
    print(list);
    clearList(&list);
    printf("%f\n", isEmpty(list));
    print(list);
    printf("%p\n", list);
    return 0;
}

void print(ListNodePtr list){
    while(list!=NULL){
        printf("%c ", list-> datum);
        list = list->next;
        }
    puts("");              
    }

void insert(ListNodePtr *listPtr, char value){
    ListNodePtr new_ptr = malloc(sizeof(ListNode));
    new_ptr->datum = value;
    ListNodePtr prevPtr = NULL;
    ListNodePtr currPtr = *listPtr;
    while(currPtr!=NULL && currPtr->datum<value){
        prevPtr = currPtr;
        currPtr = currPtr->next;
        }
    new_ptr->next = currPtr;
    if(prevPtr == NULL){
        *listPtr = new_ptr;
        }
     else {
         prevPtr->next = new_ptr;
         }
    }
/*    if (*list_ptr==NULL){        
        new_ptr->next = NULL;
        *list_ptr = new_ptr;
        }                   
    else if((*list_ptr)->datum >= value){
       new_ptr->next = *list_ptr;
       *list_ptr = new_ptr;
        }
    else{    
    ListNodePtr list = *list_ptr;
    while(list->next != NULL && list->next->datum < value){
        list = list->next;
        }
    new_ptr->next= list->next;
    list->next = new_ptr;
        }
    } */

void clearList(ListNodePtr* listPtr){
    ListNodePtr temp, list = *listPtr;
    while(list!=NULL){
        temp = list->next;
        free(list);
        list = temp;
        }
    *listPtr = NULL;
    }           


bool isEmpty(ListNodePtr list){ //this needs to be fixed
    return list==NULL;
    
    }


char get(ListNodePtr list, size_t index){ //this needs to be fixed
    if(isEmpty(list)){
        return (char)-1;
    }
    for(size_t i=0; i<index; ++i, list = list->next){
        if(list->next==NULL){
            return (char)-1;
            }
        }
    return list->datum;
    }


void delete(ListNodePtr *listPtr, char value){ //deletes a node in a list
    ListNodePtr prevPtr = NULL;
    ListNodePtr currPtr = *listPtr;
    while(currPtr!=NULL && currPtr ->datum !=value){
        prevPtr = currPtr;
        currPtr = currPtr->next;
        }
    if(currPtr ==NULL){
        return;
        }      
    if(prevPtr == NULL){
        *listPtr = currPtr->next;
        free(currPtr);
        return;
        }
    prevPtr->next = currPtr->next;
    free(currPtr);
    return;
    }

