#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

typedef struct node{
    int datum;
    struct node* next;
    }Node;

typedef struct queue{
    Node* head;
    Node* tail;
    }Queue;

Node* pop(Queue*);
void push(Queue*, Node*);
Node* peek(Queue*);
Queue* create(void);
void clear(Queue*);
void printQueue(Queue*);


int main(void){
    Queue* q = create();
    printf("Printing empty queue:\n");
    printQueue(q);
    Node* n = malloc(sizeof(Node));
    n->datum = 3;
    push(q, n);
    printf("Printing after pushing 3 onto queue:\n");
    printQueue(q);
    Node* peeked = peek(q);
    printf("This was peeked of the front of the list: %d\n", peeked->datum);
    Node* popped = pop(q);
    printf("This was popped of the front of the list: %d\n", popped->datum);
    printf("this is current queue:\n");
    printQueue(q);
    n = malloc(sizeof(Node));
    n->datum = 5;
    push(q, n);
    printf("Printing after pushing 5 onto queue:\n");
    printQueue(q);
    clear(q);
    printf("cleared queue:\n");
    printQueue(q);
    return 0;
}

Queue* create(void){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = q->tail = NULL;
    return q;
    }

void push(Queue* q, Node* n){
    if(q->tail==NULL){
        q->head = q->tail = n;
        q->tail->next = NULL;
        return;
        }
    n->next = NULL;
    q->tail->next = n;
    }

void printQueue(Queue* q){
    for(Node* n = q->head; n!=NULL; n= n->next){
        printf("%d\n", n->datum);
        }
    puts("---");
    }

void clear(Queue* q){
    while(q->head != NULL && q->head->next != NULL){
        Node* n = q->head;
        q->head = n->next;
        free(n);          
    }     
    q->head = q->tail = NULL;
}

Node* pop(Queue* q){
    if(q->head != NULL){
        Node* n = q->head;
        q->head = n->next;
        if(q->tail== n){
            q->head = q->tail =NULL;
            }
        return n;
        }
    return NULL;
    }

Node* peek(Queue* q){
    if(q->head !=NULL){
        return q->head;
        }
    return NULL;
    }
