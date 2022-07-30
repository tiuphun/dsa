#include <stdio.h>
typedef struct dllNode{
    int info;
    dllNode* next;
    dllNode* prev;
}dllNode;

void deleteNode (dllNode* dlist, dllNode* p){
    if (dlist == NULL) printf(”Empty list\n”);
    else {
        if (p == dlist) dlist = dlist->next; 
        else p->prev->next = p->next;
        if (p->next != NULL) p->next->prev = p->prev;
        else tail = p->prev;
        free(p);
    } 
}

void Remove(dllNode* dlist, int key){
    for(dllNode* cur = dlist; cur != NULL; cur = cur->next){
        if(cur->info == key) deleteNode(dlist, cur);
    }
}