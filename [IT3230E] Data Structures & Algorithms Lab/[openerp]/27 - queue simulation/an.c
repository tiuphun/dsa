#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M -999
typedef struct Node 
{
    int data;
    struct Node* next;
}Node;

Node* head, *tail;
Node* result;
int a[20]={0}, cnt=0;

Node* makeNode(int num)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = num;
    newnode->next = NULL;
    return newnode;
}

int isEmpty()
{
    return head == NULL;
}

void push(int num)
{
    Node* newnode = makeNode(num);
    if (isEmpty())
    {
        head = newnode; 
        tail = newnode;
        return;
    }
    tail->next = newnode; tail = newnode;
}

void Pop()
{
    if (isEmpty()) 
    {
        a[cnt]= M;cnt++;
        return;
    }    
    Node* temp = head;
    a[cnt] = temp->data; cnt++;
    head = temp->next;
    if (head == NULL) tail = NULL;
    free(temp);
}

int main()
{
    freopen("input.txt","r",stdin);
    char cmd[]="";
    head = NULL;
    while(1)
    {
        scanf("%s", cmd);
        if (!strcmp(cmd, "PUSH"))
        {
            int num; scanf("%d", &num);
            push(num);
        } else
        if (!strcmp(cmd, "POP"))
        {
            Pop();
        } else 
        if (!strcmp(cmd, "#")) break;
    }
    for (int i=0; i<20; i++)
    {
        if (a[i] != 0 && a[i] != M) printf("%d\n", a[i]);
        else if (a[i] != 0 && a[i] == M) printf("NULL\n");
    }
    return 0;
}