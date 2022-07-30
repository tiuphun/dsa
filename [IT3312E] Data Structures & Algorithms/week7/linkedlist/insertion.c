#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node* makeNode(int x){
    node *p = (node*)malloc(sizeof(node));
    if (p == NULL)
    {
        printf("Allocation failed.\n");
        exit(1);
    }
    else {
        p->data = x; 
        p->next = NULL;
    }
    return p;
}
/*
    Insert a new node :
    • • • •
    At the beginning of the list
    After the position pointed by the pointer cur 
    Before the position pointed by the pointer cur 
    At the end of the list
*/

// *** INSERT TO HEAD ***
//1. Pass by value
node* insertFirst(node* head, int x){ //tại sao ở code gốc của cô lại có dấu sao *? vì đó là hàm trả về biến có kiểu node*
    node *new_node = makeNode(x);
    new_node->next = head;
    head = new_node;
    return head;
}
//2. Pass by reference
void insertFirstref(node** head, int x){
    node* new_node = makeNode(x);
    new_node->next = *head;
    *head = new_node;
}


// *** AFTER CURRENT POINTER ***
node insertAfter(node* head, node* cur, int x){
    node* new_node = makeNode(x);
    if (head == NULL)   
    {
        head = new_node;
    }
    else{
        new_node->next = cur->next;
        cur->next = new_node;
    }
    return *new_node;
}

// *** BEFORE CURRENT POINTER ***
node insertBefore(node* head, node* cur, int x){
    node* prev = head;
    while (prev->next != cur) prev = prev->next;
    node* new_node = makeNode(x);
    if (head == NULL) /* list does not have any node yet */
        head = new_node;
    else if (cur == head) { //cur is the first node in the list head = new_node;
        head = new_node;
        new_node->next = cur;
    }
    else {
        prev->next = new_node;
        new_node->next = cur;
    }
    return *new_node;
}

// *** END OF LIST ***
//1. Pass by value
node insertLast(node* head, int x){
    node* new_node = makeNode(x);
    if (head == NULL) head = new_node;
    else{
        node* last = head;
        while (last->next != NULL) last = last->next;
        last->next = new_node;
    } 
    return *head;
}

//2. Pass by reference
void insertLastRef(node** head, int x){
    node* new_node = makenode(x);
    if (*head == NULL) *head = new_node; 
    else {
        node* last = *head;
        while (last->next != NULL) last = last->next; //move to the last node 
        last->next = new_node;
    } 
}

/* NOTES
    - new_node bản thân nó là con trỏ, giống như head
    - góp ý cô Phương mấy chỗ sai nhé (cái phần giá trị trả về vs. kiểu hàm ấy)
*/