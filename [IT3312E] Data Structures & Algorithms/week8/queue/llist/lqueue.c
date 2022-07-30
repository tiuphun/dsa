//QUEUE: Linked List Implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct queue{
    int data;
    struct queue* next;
}queue;
queue* head;
queue* tail;
int queueEmpty(){return head->next == NULL;}
int queueFull(){printf("Queue is full.\n") ;exit(1);}
queue* queueCreate(){
    queue* q;
    q = (queue*)malloc(sizeof(queue));
    if (q == NULL) {
        printf("Allocation failed.\n");
        return NULL;
    }
    else {
        q->next =  NULL;
        return q;
    }
}
void queuePush(){
    queue* q;
    q = (queue*)malloc(sizeof(queue));
    tail->next = q;
    q->next = NULL;
    tail = q;
}
int queuePop(){
    queue* tmp;
    if (queueEmpty()) return NULL;
    else {
        tmp = head;
        head = head->next;
        free(tmp);
        return tmp;
    }
}
void queueDisplay(){
    queue* q;
    for (q = head; q != NULL; q = q->next)
    {
        printf("%d ", q->data);
    }
}
void queueRemove(queue* q){
    while (!queueEmpty())
    {
        queuePop();
    }
    free(q);
}