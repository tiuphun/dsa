#include <stdio.h>
typedef struct dllNode
{
    int info;
    struct dllNode* next;
    struct dllNode* prev;
}dllNode;
void Remove(dllNode* dlist, int key){
    for(dllNode* cur = dlist; cur != NULL; cur = cur->next){
        if(cur->info == key){
            dllNode* tmp;
            tmp = cur->prev;
            cur->prev = cur->next;
            cur->next = tmp;
            free(cur);
            cur = tmp;
        }
    }
    for(dllNode* cur = dlist; cur != NULL; cur = cur->next) printf("%d ", cur->info);  
}