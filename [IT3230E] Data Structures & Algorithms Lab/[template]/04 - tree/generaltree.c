#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tree
{
    int key;
    struct tree* LeftMostChild;
    struct tree* RightSibling;
}node;
int leaves;
node* makeNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->key = data;
    newNode->LeftMostChild = NULL;
    newNode->RightSibling = NULL;
    return newNode;
}
int countNodes(node* root){
    if(root == NULL) return 0;
    int count = 1;
    for (node* p = root->LeftMostChild; p != NULL; p = p->RightSibling) count += countNodes(p);
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
    printf("%d ", root->key); //change data type accordingly
    node* p = root->LeftMostChild;
    while (p != NULL) {
        traversal(p);
        p = p->RightSibling;
    }
}
int CountLeaves(node* r){
    if(r == NULL) leaves += 0;
    if(r->LeftMostChild == NULL) leaves +=1;
    for(node* p = r->LeftMostChild; p!= NULL; p = p->RightSibling){
        leaves = CountLeaves(p);
    }
    return leaves;
}