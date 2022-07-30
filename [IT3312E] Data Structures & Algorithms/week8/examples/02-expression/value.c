/* Application 2: Calculate the value of an expression
    Use 2 stacks: 
    - Stack S1 stores operands
    - Stack S2 stores operators and opening brackets
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/***STACK IMPLEMENTATION***/
typedef struct stack{
    char data;
    struct stack* next;
}node;

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
void stackDisplay(node* top){
    if (stackEmpty(top)) printf("Stack is empty.\n");
    else {
        for(node* cur = top->next; cur != NULL; cur = cur->next){
            printf("%c ", cur->data);
        }
    }
}
char stackPeak(node* top){
    if (stackEmpty(top)) printf("Stack is empty.\n");
    else return top->data;
}
int stackPush(node* top, char item){
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
char stackPop(node* top){
    char data;
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
void stackRemove(node* top){
    while (!stackEmpty(top))
    {
        stackPop(top);
    }
    free(top);
}

/***SOLVER***/
int highPriority(char opt, char top){
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
void process(){
    char a = stackPop(s1);
    char b = stackPop(s1);
    char opt = stackPop(s2);
    // To convert int -> char: int i = (int)(c - '0');
    // To convert char -> int: int x = atoi(value); 
    switch (opt)
    {
    case '+':
        char r = (atoi(a) + atoi(b)) + '0';
        break;
    case '-':
        char r = (atoi(a) - atoi(b)) + '0';
        break;
    case '*':
        char r = (atoi(a) * atoi(b)) + '0';
        break;
    case '/':
        char r = (atoi(a) / atoi(b)) + '0';
        break;
    case '^':
    
    default:
        break;
    }
    
    
    stackPush(s1, r);
}
int main(int argc, char const *argv[])
{
    node* s1 = stackCreate();
    node* s2 = stackCreate();
    char input[100];
    scanf("%d", input);
    for (int i = 0; i < strlen(input); i++)
    {
        if ((input[i] > 48) && (input[i] < 57)) stackPush(s1, input[i]);
        if ((strcmp(input[i], "+") == 0) ||
            (strcmp(input[i], "-") == 0) ||
            (strcmp(input[i], "*") == 0) ||
            (strcmp(input[i], "/") == 0) ||
            (strcmp(input[i], "^") == 0){
                char opt = input[i];
                if(stackEmpty(s2)) stackPush(s2, opt);
                else if(highPriority(opt, stackPeak(s2)) == 1) stackPush(s2, opt);
                else if(highPriority(opt, stackPeak(s2)) == 0){
                    while(highPriority(opt, stackPeak(s2)) == 0) process();
                    stackPush(s2, opt);
                }
           }
        if (strcmp(input[i], "(") == 0)) stackPush(s2, input[i]);
        if (strcmp(input[i], ")") == 0){
            while(stackPeak(s2) != 40) process();
            stackPop(s2);
        }
    }
    while(stackEmpty(s1) == 0) process();

    return 0;
}

/* NOTES: Chưa xong đâu nhé. Mới chỉ là viết theo ý tưởng trong slide chứ chưa hiểu gì cả.
    - Làm sao để xử lí B OPT A và trả về kết quả như một phép toán? Rồi lại đưa R vào như một char?
    - Mà chúng ta đang làm gì vậy nhỉ?

*/