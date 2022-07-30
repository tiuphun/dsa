#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100
typedef struct tree
{
    char name[MAX_LENGTH];
    struct tree* LeftMostChild;
    struct tree* rightSibling;
}node;
char ChildName[MAX_LENGTH];
char ParentName[MAX_LENGTH];
node* nodes[10001];
int n; //numbers of people
node* find(char* name){
    for (int i = 0; i < n; i++) if(strcmp(name, nodes[i]->name)==0) return nodes[i];
    return NULL;
}
void addChild(node* child, node* parent){
    //add the node child at the beginning of the children list
    if(parent->LeftMostChild == NULL){parent->LeftMostChild = child; return;}
    child->rightSibling = parent->LeftMostChild;
    parent->LeftMostChild = child;
}
node* makeNode(char* name){
    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->name, name);
    newNode->LeftMostChild = NULL;
    newNode->rightSibling = NULL;
    return newNode;
}
void insertNode(node* newNode){
    n++;
    nodes[n-1] = newNode;
}
int countNodes(node* root){
    if(root == NULL) return 0;
    int count = 1;
    for (node* p = root->LeftMostChild; p != NULL; p = p->rightSibling) count += countNodes(p);
    return count;
}
int height(node* root){
    if(root == NULL) return 0;
    int max_height = 0;
    for (node* p = root->LeftMostChild; p != NULL; p = p->rightSibling) {
        int h = height(p);
        if (h > max_height) max_height = h;
    }
    return max_height + 1;
}