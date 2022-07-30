//Example 01: Parentheses Matching - DONE!!! (21.5.2022)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char input[1000000];
typedef struct s{
    char key;
    struct s* next;
}stack;
stack* top;
stack* s;
int stackEmpty(){return top == NULL;}
void stackPush(char data){
    stack* new_node;
    new_node = (stack*)malloc(sizeof(stack));
    if (new_node == NULL) printf("Allocation failed.\n");
    new_node->key = data;
    if (top == NULL){
        new_node->next = NULL;
        top = new_node;
    }
    else{
        new_node->next = top;
        top = new_node;
    }
}
void stackPop(){
    stack* del;
    if(top == NULL) printf("UNDERFLOW\n");
    else{
        del = top;
        top = top->next;
        free(del);
    }
}
int checkPair(char open, char close){
    if((open == '(') && (close == ')')) return 1;
    if((open == '[') && (close == ']')) return 1;
    if((open == '{') && (close == '}')) return 1;
    return 0;
}
void checktoPush(char c){
    if ((c == '(') || (c == '[') || (c == '{')) stackPush(c);
    if ((c == ')') || (c == ']') || (c == '}')){
        if (checkPair(top->key, c)) stackPop();
    }
}
int main(int argc, char const *argv[])
{
    scanf(" %s", input);
    for (int i = 0; i <= strlen(input); i++)
    {
        checktoPush(input[i]);
    }
    if (stackEmpty()) printf("1\n");
    else printf("0\n");
    return 0;
}
/* NOTES ***
    - Since using strcmp() requires pointer to strings, and that would complicating the code, hence we:
        + Write a custom checkPair() function instead. (long as hell)
        + Comparing string as <int> value in ASCII table instead of as <char> (using '' instead of "")
    - NEVER USE == TO COMPARE TWO STRINGS!!! (logic err, appear fine and good but secretly make everything wrong)
*/