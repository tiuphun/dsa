/*
    Perform a sequence of operations over a queue, each element is an integer:
    PUSH v: push a value v into the queue
    POP: remove an element out of the queue and print this element to stdout (print NULL if the queue is empty)
    Input
    Each line contains a command (operration) of type
    PUSH  v
    POP
    Output
    Write the results of POP operations (each result is written in a line)
    Example
    Input
    PUSH 1
    PUSH 2
    PUSH 3
    POP
    POP
    PUSH 4
    PUSH 5
    POP
    #
    Output
    1
    2
    3

    Input
    PUSH 1
    POP
    POP
    PUSH 4
    POP
    #
    Output
    1
    NULL
    *4/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue{
    int data;
    struct queue* next;
}node;
node* head = NULL;
node* tail = NULL;

int queueEmpty(node* head){return head == NULL;}
node* queueCreate(node* head, int key){
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) return NULL;
    else {
        newNode->data = key;
        newNode->next =  NULL;
        return newNode;
    }
}
node* queuePush(node* head, int key){
    node* newNode = queueCreate(head, key);
    if (queueEmpty(head)) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    return newNode;
}

void queuePop(node* head){
    if (queueEmpty(head)) printf("NULL\n");
    else {
        node* tmp = head;
        head = head->next;
        if (head == NULL) tail = NULL;
        printf("%d\n", tmp->data);
        free(tmp);
    }
}

void queueDisplay(node* head){
    for (node* cur = head; cur != NULL; cur = cur->next)
    {
        printf("%d ", cur->data);
    }
}

int main(int argc, char const *argv[])
{
    freopen("input.txt","r",stdin);
    
    char input[10]; int key;
    while(1){
        scanf("%s", input);
        //printf("%s\n", input);
        if(strcmp(input, "PUSH") == 0){
            scanf("%d", &key);
            queuePush(head, key);
            printf("%d\n", head->data);
            queueDisplay(head);
        }
        if(strcmp(input, "POP") == 0){
            queuePop(head);
        }
        if(strcmp(input, "#") == 0) break;
    }
    return 0;
}
