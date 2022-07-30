//STACK: Array Implementation
#include <stdio.h>
#include <stdlib.h>
static int* stack;
static int maxSize;//maximum number of elements that the stack could have 
static int numItems; //current number of elements on stack 
void stackInit(int maxSize)
{
    stack = (int*)malloc(maxSize*sizeof(int));
    numItems = 0; 
}
int stackEmpty(){return numItems==0;}
int stackFull() {return numItems==maxSize;}
void stackPush(int item){
    if (stackFull()){
        printf("Stack is full.\n"); 
        exit(1);
    }
    else 
    {   stack[numItems] = item;
        numItems++;
    }
}
int stackPop(){
    if(stackEmpty()){
        printf("Stack is empty.\n");
        exit(1);
    }
    else{
        numItems--;
        return stack[numItems+1];
    }
}
void stackDisplay(){
    if (stackEmpty()) printf("Stack is empty!\n");
    else {
        for (int i = 0; i < numItems; i++)
        {
            printf("%d ", stack[i]);
        }
        
    }
}