#include <stdio.h>
struct Node
{
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
        LIST* prev = head;
        while(prev->next != del) prev = prev->next;
        prev->next = del->next;
        free(del);
    }
    return head;
}

LIST* OddList(LIST* Linp){ //Linp is the pointer to the beginning of the list
    int position = 1;
    for(LIST* cur = Linp; cur != NULL; cur = cur->next){
        if(position % 2 == 0) deleteNode(Linp, cur);
        position++;
    }
    return Linp;
}
