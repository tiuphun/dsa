#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int data;
    struct node *next;
}node;
node *makeNode(int v){
    node* p = (node*)malloc(sizeof(node));
    if (p == NULL)
    {
        printf("Allocation failed.\n");
        exit(1);
    }
    else {
        p->data = v; 
        p->next = NULL;
    }
    return p;
}
void insert_to_head(node **head, int x){
    node *newNode = makenode(x);
    newNode->next = *head;
    *head = newNode;
}

node *insert_to_head(node *head, int x){
    node *newNode = makeNode(x);
    newNode->next = head;
    head = newNode;
    return head;
}
int main(int argc, char const *argv[])
{
    int n, tmp;
    node *head = NULL;

    printf("Enter n = "); scanf("%d", &n);
    for (int i = 1; i < ; i++)
    {
        printf("Enter number %d: ", i);
        scanf("%d", &tmp);
        head = insert_to_head(head, tmp);
    }
    
    node *cur = head;
    for(cur = head; cur != NULL; cur = cur->next){
        printf("%d ", cur->data);
    }
    return 0;
}
