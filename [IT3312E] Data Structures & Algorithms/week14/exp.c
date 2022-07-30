/* NOT DONE
    - How to strcpy 2 char instead of char*?
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1000
char EH[MAX_LENGTH], infix[MAX_LENGTH];
int answer;

//Stack Implementation
typedef struct stack{
    char data;
    struct stack* next;
}node;
node* convertStack; //top of stack to store expression while converting infix -> postfix
node* operandStack; //top of stack to store operand while evaluating the expression

int stackEmpty(node* top){
    return (top->next == NULL);
}
int stackFull(){ 
    printf("Stack is full.\n");
    exit(1);
}
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
int stackPush(node* top, char* item){
    node* new_node;
    new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL){
        stackFull(); return 1;
    }
    else{
        strcpy(new_node->data, item);
        new_node->next = top->next;
        top->next = new_node;
        return 0;
    }
}
char* stackPop(node* top){
    char data;
    node* tmp;
    if(stackEmpty(top)) return 0;
    else{
        strcpy(tmp, top->next);
        strcpy(data, tmp->data);
        strcpy(top->next, tmp->next);
        free(tmp);
        return tmp->data;
    }
}
char* stackPeak(){
    if (stackEmpty(top)) printf("Stack is empty.\n");
    else return top->data;
}

//Additional Functions
int isHighPriority(char opt, char top){
    //A function that return TRUE if OPT has higher priority than TOP
    if(strcmp(top, "^") == 0){
        switch (opt)
        {
        case '^': case '*': case '/': case '+': case '-': 
            return 0; break;
        default:
            break;
        }
    }
    if((strcmp(top, "*") == 0) || (strcmp(top, "/") == 0)){
        switch (opt)
        {
        case '^':
            return 1; break;
        case '*': case '/': case '+': case '-': 
            return 0; break;
        default:
            break;
        }
    }
    if((strcmp(top, "+") == 0) || (strcmp(top, "-") == 0)){
        switch (opt)
        {
        case '^': case '*': case '/':
            return 1; break;
        case '+': case '-': 
            return 0; break;
        default:
            break;
        }
    }
}
int isOperator(char* input){
    return ((strcmp(input, "+") == 0) ||                                            
            (strcmp(input, "-") == 0) ||
            (strcmp(input, "*") == 0) ||
            (strcmp(input, "/") == 0) ||
            (strcmp(input, "^") == 0));
}
int isOperand(char* input){
    return ((input >= 48) && (input <= 57));
}

//Converting Infix to Postfix
void InfixToPostfix(char* infix, node* top){
    char x, y;
    int i, j;
    for(i = 0, j = 0; i < strlen(infix); i++){
        x = infix[i]; y = stackPeak(top);
        if (isOperand(x)) {strcpy(EH[j], x); j++;} 
        if (strcmp(x, "(") == 0) stackPush(x);                           
        if (isOperator(x))
        {
            if((stackEmpty(top)) || (strcmp("(", top) == 0)) stackPush(x);
            if(isOperator(y) && (!=isHighPriority(y, x))) stackPush(x);
            if(isOperator(y) && isHighPriority(y, x)) {
                strcpy(EH[j] = stackPop(top)); 
                j++;
            }
        }
        if (strcmp(x, ")") == 0){
            while((!= stackEmpty(top)) || (strcmp(y, "(") == 0)){
                if(isOperator(y)) {
                    strcpy(EH[j], stackPop(top)); 
                    j++;
                }
            }
            if(strcmp(y, "(") == 0) stackPop(top);
        }
    }
    while (!= stackEmpty(top))
    {
        strcpy(EH[j], stackPop(top));
        j++;
    }
}

//Evaluating Postfix Expressions
/*void evaluationPostfix(char* expression, node* top){
    for (int i = 0; i < strlen(expression); i++)
    {
        if (isOperand(expression[i])) stackPush(top, expression[i]);
        if (isOperator(expression[i]))
        {
            char operand1 = stackPop(top);
            char operand2 = stackPop(top);
            char opt = expression[i];
            char result;
            // To convert int -> char: int i = (int)(c - '0');
            // To convert char -> int: int x = atoi(value); 
            switch (opt)
            {
                case '+':
                    result = (atoi(operand2) + atoi(operand1)) + '0';
                    break;
                case '-':
                    result = (atoi(operand2) - atoi(operand1)) + '0';
                    break;
                case '*':
                    result = (atoi(operand2) * atoi(operand1)) + '0';
                    break;
                case '/':
                    result = (atoi(operand2) / atoi(operand1)) + '0';
                    break;
                case '^':
                    result = (atoi(operand2) ^ atoi(operand1)) + '0';
                    break;
                default:
                    break;
            }
            stackPush(top, result);
        }
    }
    answer = atoi(stackPop(operandStack));
}
*/
int main(int argc, char const *argv[])
{
    scanf("%s", infix);
    InfixToPostfix(infix, convertStack);
    puts(postfix);
    //evaluationPostfix(postfix, operandStack);
    //printf("%d\n", answer);
    return 0;
}
