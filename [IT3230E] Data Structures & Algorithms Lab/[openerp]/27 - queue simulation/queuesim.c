/* WRONG
    Perform a sequence of operations over a queue, each element is an integer:
    PUSH v: push a value v into the queue
    POP: remove an element out of the queue and print this element to stdout (print NULL if the queue is empty)
    cmd
    Each line contains a command (operration) of type
    PUSH  v
    POP
    Output
    Write the results of POP operations (each result is written in a line)
    Example
    cmd
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

    cmd
    PUSH 1
    POP
    POP
    PUSH 4
    POP
    #
    Output
    1
    NULL
    4
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EMPTY INT32_MAX
#define SIZE 10
typedef struct queue{
    int data;
    struct queue* next;
}node;
node* head = NULL;
node* tail = NULL;
int pop[SIZE] = {0}, count = 0; //array to store popped elements

int queueEmpty(node* head){return head == NULL;}
node* queueCreate(int key){
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) return NULL;
    else {
        newNode->data = key;
        newNode->next =  NULL;
        return newNode;
    }
}
void queuePush(node* head, node* tail, int key){
    node* newNode = queueCreate(key);
    if (queueEmpty(head)) {
        head = newNode;
        tail = newNode;
        return;
    }
    else {
        tail->next = newNode;
        tail = newNode;
        return;
    }
}

void queuePop(node* head){
    if (queueEmpty(head)){
        pop[count] = EMPTY; count++;
        return;
    }
    node* tmp = head;
    pop[count] = tmp->data; count++;
    head = tmp->next;
    if (head == NULL) tail = NULL;
    free(tmp);
}

int main(int argc, char const *argv[])
{
    freopen("input.txt","r",stdin);
    char cmd[SIZE]; int key;
    while(1){
        scanf("%s", cmd);
        if (strcmp(cmd, "PUSH") == 0){
            scanf("%d", &key);
            queuePush(head, tail, key);
        }
        else if (strcmp(cmd, "POP") == 0){
            queuePop(head);
        }
        else if (strcmp(cmd, "#") == 0) break;
    }
    for (int i = 0; i < SIZE; i++)
    {
        if (pop[i] != 0 && pop[i] != EMPTY) printf("%d\n", pop[i]);
        else if (pop[i] != 0 && pop[i] == EMPTY) printf("NULL\n");
    }
    
    return 0;
}
