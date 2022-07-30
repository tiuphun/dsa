//Insert an element before a certain element in a list
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int id;
    struct Node* next;
}Node;

Node* makeNode(int id){
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id; p->next = NULL;
    return p;
}

void printList(Node* h){
    for(Node* p = h; p != NULL; p = p->next){
        printf("%d ", p->id);
    }
    printf("\n");
}

Node* insertBefore(int id, int v, Node* h){
    if(h == NULL) return NULL;
    if(h->id == v){
        Node* q = makeNode(id);
        q->next = h;
        return q;
    }
    Node* p = h;
    while (p->next != NULL)
    {
        if (p->next->id == v)
        {
            Node* q = makeNode(id);
            q->next = p->next;
            p->next = q;
            return h;
        }
        p = p->next;
    }
    return h;
}

int main(int argc, char const *argv[])
{
    Node* h = NULL;
    h = makeNode(1);
    for (int i = 2; i <= 5; i++)
    {
        h = insertBefore(i, i-1, h);
    }
    printList(h);
    h = insertBefore(6, 3, h);
    printList(h);
        
    return 0;
}
