#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node{
    int Inf;
    struct Node* next;
};
typedef struct Node LIST;

LIST* deleteNode(LIST* head, LIST* del){
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

LIST* OddList(LIST* Linp){ //suppose Linp is the pointer to the beginning of the list
    LIST* Lout;
    for(LIST* cur = Linp; cur != NULL; cur = cur->next){
        if(cur->Inf % 2 == 0) deleteNode(Linp, cur);
    }
    Lout = Linp;
    return Lout;
}