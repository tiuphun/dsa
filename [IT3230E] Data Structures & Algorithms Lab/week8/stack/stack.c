/*
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
    3
    2
    5
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack{
    int data;
    struct stack* top;
}stack;
stack* s;
int stackEmpty(stack* s){
    return (s->top == NULL);
}
int stackFull(){ //HOW TO CHECK IF STACK IS FULL? OUT OF MEMORY?
    printf("Stack is full.\n");
    exit(1);
}
stack* stackCreate(){
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
void stackDisplay(stack* s){
    stack* node;
    if (stackEmpty(s)) printf("Stack is empty");
    else {
        for(node = s->top; node != NULL; node = node->top){
            printf("%d\n", node->data);
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
    int tmp;
    stack* node;
    if(stackEmpty(s)) { 
        return 0;
    }
    else{
        node = s->top;
        tmp = node->data;
        s->top = node->top;
        free(node);
        return tmp;
    }
}
int main(int argc, char const *argv[])
{
    
    char cmd[10]; int new, pop;
    s = stackCreate();
    while(1){
        scanf("%s", cmd);
        if (strcmp(cmd, "PUSH") == 0){
            scanf("%d", &new);
            stackPush(s, new);
        }
        else if(strcmp(cmd, "POP") == 0){
            pop = stackPop(s);
            if (pop == 0) printf("NULL\n");
            else printf("%d\n", pop);
            
        }
        else if(strcmp(cmd, "#") == 0){
            break;
        }
        else continue;
    }
    
    
    return 0;
}
