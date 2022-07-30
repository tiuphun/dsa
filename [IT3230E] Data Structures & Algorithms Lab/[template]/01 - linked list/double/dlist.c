#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct dllist
{
    int data;
    struct dllist* next;
    struct dllist* prev;
}node;
node* head, tail;

void deleteNode (node* del){
    if (head == NULL) printf(”Empty list”);
    else {
        if (del == head) head = head->next; //Delete first element 
        else del->prev->next = p->next;
        if (del->next != NULL) del->next->prev = del->prev;
        else tail = del->prev;
        free(del);
    } 
}
void InsertNode (int x){
    if (head == NULL){ 
        head = (node*)malloc(sizeof(node));
        head->data = x;
        head->prev = NULL;
        head->next = NULL;
    } 
    else{
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = x;
        newNode->next = NULL;
    }
}

/* Insert a new node p at the end of the list */
void append_node(node* p);
/* Insert a new node p after a node pointed by the pointer after */
void insert_node(node* p, node* after);
/* Delete a node pointed by the pointer p */
void delete_node(node* p);
