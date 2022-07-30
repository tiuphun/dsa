//CHECKED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tree
{
    int id;
    struct tree* leftChild;
    struct tree* rightChild;
}node;
node* root;
node* MakeRoot(int u){
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {printf("Allocation failed\n"); exit(1);}
    else{
        newNode->id = u;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
    }
    return newNode;
}
node* find(int id, node* root){ //Find node by id
    if (root == NULL) return NULL;
    if (root->id == id) return root;
    node* p = find(id, root->leftChild);
    if (p != NULL) return p;
    else {
        p = find(id, root->rightChild);
        if (p != NULL) return p;
        else return NULL;
    }
}
node* AddLeft(int u, int v){
    node* p = find(v, root);
    if((find(v, root) == NULL) || (find(u, root) != NULL) || p->leftChild != NULL) return NULL;
    else{
        p->leftChild = MakeRoot(u);
    }
    return p->leftChild;
}
node* AddRight(int u, int v){
    node* p = find(v, root);
    if((find(v, root) == NULL) || (find(u, root) != NULL) || p->rightChild != NULL) return NULL;
    else{
        p->rightChild = MakeRoot(u);
    }
    return p->rightChild;
}
void PreOrder(node* root){
    if(root == NULL) return;
    else{
        printf("%d ", root->id);
        PreOrder(root->leftChild);
        PreOrder(root->rightChild);
    }
}
void InOrder(node* root){
    if(root == NULL) return;
    else{
        InOrder(root->leftChild);
        printf("%d ", root->id);
        InOrder(root->rightChild);
    }
}
void PostOrder(node* root){
    if(root == NULL) return;
    else{
        PostOrder(root->leftChild);
        PostOrder(root->rightChild);
        printf("%d ", root->id);
    }
}