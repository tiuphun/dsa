#include <stdio.h>
#include <stdlib.h>

typedef struct llist
{
    int data;
    struct llist* next;
}node;
node* head;

int isEmpty(node* head){
    return (head == NULL);
}

// ********************************* CREATION **************************************
node* makeNode(int x){
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) return NULL;
    else {
        new_node->data = x; 
        new_node->next = NULL;
    }
    return new_node;
}

// ********************************* TRAVERSION ************************************
void traverse(node* head){
    node* cur;
    for(cur = head; cur != NULL; cur = cur->next) printf("%d ", cur->data);
}

// ********************************* INSERTION *************************************
// A - INSERT TO HEAD
node* insertFirst(node* head, int x){ 
    node *new_node = makeNode(x);
    new_node->next = head;
    head = new_node;
    return head;
}

// B - INSERT AFTER CURRENT POINTER
node* insertAfter(node* head, node* cur, int x){
    node* new_node = makeNode(x);
    if (head == NULL)   
    {
        head = new_node;
    }
    else{
        new_node->next = cur->next;
        cur->next = new_node;
    }
    return new_node;
}

// C - BEFORE CURRENT POINTER 
node* insertBefore(node* head, node* cur, int x){
    node* prev = head;
    while (prev->next != cur) prev = prev->next;
    node* new_node = makeNode(x);
    if (head == NULL) 
        head = new_node;
    else if (cur == head) {
        head = new_node;
        new_node->next = cur;
    }
    else {
        prev->next = new_node;
        new_node->next = cur;
    }
    return new_node;
}

// D - END OF LIST
node* insertLast(node* head, int x){
    node* new_node = makeNode(x);
    if (head == NULL) head = new_node;
    else{
        node* last = head;
        while (last->next != NULL) last = last->next;
        last->next = new_node;
    } 
    return head;
}

// ********************************* DELETION *************************************
// A - DELETE A NODE
node* deleteNode(node* head, node* del){
    if (del == head){
        head = del->next;
        free(del);
    }
    else {
        node* prev = head;
        while(prev->next != del) prev = prev->next;
        prev->next = del->next;
        free(del);
    }
    return head;
}

// B - DELETE ALL NODES
node* deleteAll(node* head){
    for(node* del = head; del != NULL; head = head->next){
        free(del);
        del = head;
    }
    return head;
}

// ********************************* SEARCH ***************************************
node* search(int x){
    node* cur;
    for(cur = head; cur != NULL; cur = cur->next){
        if(cur->data == x) break;
    }
    return cur;
}

// ********************************* ADDITIONALS **********************************
node* reverse(node* head){
    node* p = head;
    node* pp = NULL;
    node* np = NULL;
    while(p != NULL){
        np = p->next;
        p->next = pp;
        pp = p;
        p = np;
    }
    return pp;
}