//STACK: Linked List Implementation
#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
    int data;
    struct stack* top;
}stack;
stack* head;
void stackCreate(){
    stack* s;
    s = (stack*)malloc(sizeof(stack));
    if (s == NULL) {
        printf("Allocation failed.\n");
        return NULL;
    }
    else {
        s->top =  NULL;
        return s;
    }
}
void stackRemove(stack* s){
    while (!stackEmpty(s))
    {
        stackPop(s);
    }
    free(s);
}
int stackEmpty(stack* s){
    return (s->top == NULL);
}
int stackFull(){ //HOW TO CHECK IF STACK IS FULL? OUT OF MEMORY?
    printf("Stack is full.\n");
    exit(1);
}
void stackDisplay(stack* s){
    stack* node;
    if (stackEmpty(s)) printf("Stack is empty");
    else {
        for(node = head->top; node != NULL; node = node->top){
            printf("%d ", node->data);
        }
    }
}
int stackPush(stack* s, int item){
    stack* node;
    node = (stack*)malloc(sizeof(stack));
    if(node == NULL){
        stackFull(); return 1;
    }
    else{
        node->data = item;
        node->top = s->top;
        s->top = node;
        return 0;
    }
}
int stackPop(stack* s){
    float data;
    stack* node;
    if(stackEmpty(s)) return NULL;
    else{
        node = s->top;
        data = node->data;
        s->top = node->top;
        free(node);
        return node->data;
    }
}
