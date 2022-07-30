#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int data;
    struct queue* next;
}node;
node* head;
node* tail;

int queueEmpty(){return head->next == NULL;}
int queueFull(){printf("Queue is full.\n") ;exit(1);}

// ********************************* CREATION **************************************
node* queueCreate(){
    node* new_node;
    new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Allocation failed.\n");
        return NULL;
    }
    else {
        new_node->next =  NULL;
        return new_node;
    }
}

// ********************************* PUSH **************************************
void queuePush(){
    node* new_node;
    new_node = (node*)malloc(sizeof(node));
    tail->next = new_node;
    new_node->next = NULL;
    tail = new_node;
}

// ********************************* POP **************************************
int queuePop(){
    node* tmp;
    if (queueEmpty()) return NULL;
    else {
        tmp = head;
        head = head->next;
        free(tmp);
        return tmp;
    }
}

// ********************************* TRAVERSE **************************************
void queueDisplay(){
    for (node* cur = head; cur != NULL; cur = cur->next)
    {
        printf("%d ", cur->data);
    }
}

// ********************************* DELETION **************************************
void queueRemove(node* head){
    while (!queueEmpty())
    {
        queuePop();
    }
    free(head);
}