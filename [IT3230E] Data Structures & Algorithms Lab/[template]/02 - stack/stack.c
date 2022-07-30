//top = head
#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int data;
    struct stack* next;
}node;
node* top;

int stackEmpty(node* top){
    return (top->next == NULL);
}
int stackFull(){ 
    printf("Stack is full.\n");
    exit(1);
}

// ********************************* CREATION **************************************
node* stackCreate(){
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

// ********************************* TRAVERSE **************************************
void stackDisplay(node* top){
    if (stackEmpty(top)) printf("Stack is empty.\n");
    else {
        for(node* cur = top->next; cur != NULL; cur = cur->next){
            printf("%d ", cur->data);
        }
    }
}

// ********************************* PEAK ******************************************
int stackPeak(node* top){
    if (stackEmpty(top)) return 0;
    else return top->data;
}

// ********************************* PUSH ******************************************
int stackPush(node* top, int item){
    node* new_node;
    new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL){
        stackFull(); return 1;
    }
    else{
        new_node->data = item;
        new_node->next = top->next;
        top->next = new_node;
        return 0;
    }
}

// ********************************* POP *******************************************
int stackPop(node* top){
    int data;
    node* tmp;
    if(stackEmpty(top)) return NULL;
    else{
        tmp = top->next;
        data = tmp->data;
        top->next = tmp->next;
        free(tmp);
        return tmp->data;
    }
}

// ********************************* DELETION **************************************
void stackRemove(node* top){
    while (!stackEmpty(top))
    {
        stackPop(top);
    }
    free(top);
}