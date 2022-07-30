#include <stdio.h>
typedef struct ListNode
{
    int info;
    struct ListNode* next;
}ListNode;

ListNode* deleteNode(ListNode* head, ListNode* del){
    if (del == head){
        head = del->next;
        free(del);
    }
    else {
        ListNode* prev = head;
        while(prev->next != del) prev = prev->next;
        prev->next = del->next;
        free(del);
    }
    return head;
}
ListNode* removeDupes(ListNode* list){
    int visited[1000] = {};
    for(ListNode* cur = list; cur != NULL; cur = cur->next){
        if(visited[cur->info] != 0) deleteNode(list, cur); 
        else visited[cur->info] = 1;
    }
    return list;
}
