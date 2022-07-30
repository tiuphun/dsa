void processRemove(int v){
    Node* p = head;
    if(head == NULL) return;
    if(head->key == v){
        Node* tmp = head;
        head = head->next;
        if(head == NULL) last = NULL;
        free(tmp); return;
    }
    while(p->next != NULL){// find the pointer p such that p->next->key = v
        if(p->next->key == v) break;
        p = p->next;
    }
    if(p->next == NULL) return; // node having key = v does not exist
    Node* tmp = p->next;
    p->next = p->next->next;
    if(last == tmp) last = p;
    free(tmp);
}