// Spin-off: Changing the record: From a simple int -> A record contains name, address,... additional fields.
// Hash table implementation - OK
#include <stdio.h>
#include <stdlib.h>
#define M 10007 //best to choose a prime number
typedef struct llist{
    unsigned long long key;
    struct llist* next;
}node;
node* T[M] = {NULL}; 
int hash(unsigned long long key){
    return (key % M);
}
node* makeNode(unsigned long long key){
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) return NULL;
    else {
        newNode->key = key; 
        newNode->next = NULL;
    }
    return newNode;
}
node* findList(node* head, unsigned long long key){
    node* p = head;
    while(p != NULL){
        if (p->key == key) return p;
        p = p->next;
    }
    return NULL;
}
node* insertList(node* head, unsigned long long key){
    node* p = findList(head, key);
    if (p == NULL){ //only insert if key is not present
        node* newNode = makeNode(key);
        newNode->next = head;
        head = newNode;
        return newNode;
    }
    return NULL;
}


//Find an element with certain key in the database: Return 1 if found, 0 otherwise
int find(unsigned long long key){
    int index = hash(key);
    node* result = findList(T[index], key);
    if (result != NULL) return 1;
    else return 0;
}

//Return the result of insertion: 1 if successful, 0 otherwise
int insert(unsigned long long key){
    int index = hash(key);
    node* found = findList(T[index], key);
    if (found != NULL) return 0;
    else{
        T[index] = insertList(T[index], key);
        return 1;
    }
}
int main(int argc, char const *argv[])
{
    int n = 10; int k;
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        insert(k);
    }
    int f; 
    printf("f = "); scanf("%d", &f);
    int result = find(f);
    printf("%d\n", result);
        
    return 0;
}
