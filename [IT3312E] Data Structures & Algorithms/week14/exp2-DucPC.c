#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LENGTH 1000
#define DEBUG(s, top) puts(s); stackDisplay(top);
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
    if (top->next == NULL) return 1;
    return 0;
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
        strcpy(item, &new_node->data);
        new_node->next = top->next;
        top->next = new_node;
        return 0;
    }
}
char* stackPop(node* top){
    char* data;
    node* tmp;
    if(stackEmpty(top)) return NULL;
    else{
        tmp =  top->next;
        strcpy(data, &tmp->data);
        top->next = tmp->next;
        free(tmp);
        return &tmp->data;
    }
}
char* stackPeak(node* top){
    if (stackEmpty(top)) return 0;
    else return &top->data;
}
void stackDisplay(node* top){
    if (stackEmpty(top) == 1) printf("Stack is empty.\n");
    else {
        for(node* cur = top; cur != NULL; cur = cur->next){
            printf("%c ", cur->data);
        }
    }
}
//Additional Functions
int isHighPriority(char* popt, char* top){
    char opt = *popt;
    //A function that return 1 if OPT has higher priority than TOP; 0 if not
    if(strcmp(top, "^") == 0){
        switch (opt)
        {
        case '^': case '*': case '/': case '+': case '-': 
            return 0; break;
        default:
            return -1; break;
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
            return -1; break;
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
            return -1; break;
        }
    }
    return -1;
}
int isOperator(char* input){
    return ((strcmp(input, "+") == 0) ||                                            
            (strcmp(input, "-") == 0) ||
            (strcmp(input, "*") == 0) ||
            (strcmp(input, "/") == 0) ||
            (strcmp(input, "^") == 0));
}
int isOperand(char* input){
    char x = *input;
    return ((x >= 48) && (x <= 57));
}

//Converting Infix to Postfix
/*void InfixToPostfix(char* infix, node* top){
    char* x; char* y;
    int i, j;
    for(i = 0, j = 0; i < strlen(infix); i++){
        DEBUG(EH, convertStack);
        x = &infix[i]; y = stackPeak(top);
        if (isOperand(x)) {strcpy(&EH[j], x); j++;} 
        if (strcmp(x, "(") == 0) stackPush(convertStack, x);                           
        if (isOperator(x))
        {
            if((stackEmpty(top) != 0) || (strcmp("(", y) == 0)) stackPush(convertStack,x);
            if(isOperator(y) && (isHighPriority(y, x) == 0)) stackPush(convertStack, x);
            if(isOperator(y) && (isHighPriority(y, x) == 1)) {
                strcpy(&EH[j], stackPop(top)); 
                j++;
            }
        }
        if (strcmp(x, ")") == 0){
            if(isOperator(y)){
                while((stackEmpty(top) == 0) || (strcmp(y, "(") != 0)){
                    strcpy(&EH[j], stackPeak(top));
                    stackPop(top);
                    j++;
                }
            }
            if(strcmp(y, "(") == 0) stackPop(top);
        }
        
    }
    while (stackEmpty(top) == 0)
    {
        strcpy(&EH[j], stackPop(top));
        j++;
    }
}*/

//Evaluating Postfix Expressions
void evaluationPostfix(char* expression, node* top){
    char* x;
    for (int i = 0; i < strlen(expression); i++)
    {
        x = &expression[i];
        if (isOperand(x)) stackPush(top, x);
        if (isOperator(x))
        {
            char* operand1 = stackPop(top);
            char* operand2 = stackPop(top);
            char opt = *x;
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
            stackPush(top, &result);
        }
    }
    answer = atoi(stackPop(operandStack));
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    scanf("%[^\n]", infix);
    //convertStack = stackCreate();
    //InfixToPostfix(infix, convertStack);
    //puts(EH);
    operandStack = stackCreate();
    DEBUG(EH, operandStack);
    evaluationPostfix(EH, operandStack);
    printf("%d\n", answer);
    return 0;
}
