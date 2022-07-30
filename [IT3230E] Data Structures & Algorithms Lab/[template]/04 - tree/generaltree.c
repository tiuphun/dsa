#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tree
{
    int key;
    struct tree* LeftMostChild;
    struct tree* RightSibling;
}node;
node* MakeNode(int u){
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) return NULL;
    else{
        newNode->key = u;
        newNode->LeftMostChild = NULL;
        newNode->RightSibling = NULL;
        return newNode;
    }
}
node* find(node* root, int key){ 
    if (root == NULL) return NULL;
    if (root->key == key) return root;
    node* p = root->LeftMostChild;
    while (p != NULL) {
        node* q = find(p, key);
        if (q != NULL) return q;
        p = p->RightSibling;
    }
    return NULL;
}
int countNodes(node* root){
    
}
int CountKChildren(node* r, int k){
    int count = 0;
    if (r == NULL) return 0;
    int nodes = 0;
    for (node* p = r->LeftMostChild; p != NULL; p = p->RightSibling) nodes++;
    if (nodes == k) count++;
    for (node* p = r->LeftMostChild; p != NULL; p = p->RightSibling) count += CountKChildren(p, k);
    return count;
}
int height(node* root){
    if(root == NULL) return 0;
    int max_height = 0;
    for (node* p = root->LeftMostChild; p != NULL; p = p->RightSibling) {
        int h = height(p);
        if (h > max_height) max_height = h;
    }
    return max_height + 1;
}
void traversal(node* root){
    printf("%d ", root->key);
    node* p = root->LeftMostChild;
    while (p != NULL) {
        traversal(p);
        p = p->RightSibling;
    }
}
int CountLeaves(node* r){
    int leaves = 0;
    if (r == NULL) return 0; 
    if (r->LeftMostChild == NULL) return 1;
    for (node* p = r->LeftMostChild; p!= NULL; p = p->RightSibling){
        leaves += CountLeaves(p);
    }
    return leaves;
}