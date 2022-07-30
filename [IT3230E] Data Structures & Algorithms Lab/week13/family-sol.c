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
int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    while (1)
    {
        scanf("%s", ChildName);
        if(strcmp(ChildName, "***")==0) break;
        scanf("%s", ParentName);
        node* child = find(ChildName);
        node* parent = find(ParentName);
        if(child == NULL){
            child = makeNode(ChildName);
            insertNode(child);
        }
        if(parent == NULL){
            parent = makeNode(ParentName);
            insertNode(parent);
        }
        addChild(child, parent);
    }
    
    char cmd[MAX_LENGTH], name[MAX_LENGTH];
    while (1)
    {
        scanf("%s", cmd);
        if(strcmp(cmd, "***")==0) break;
        scanf("%s", name);
        node* p = find(name);
        if(strcmp(cmd, "descendants")==0){
            int ans = countNodes(p);
            ans = ans-1; //exclude the root node itself
            printf("%d\n", ans);
        }
        if(strcmp(cmd, "generation")==0) {
            int ans = height(p);
            ans = ans-1;
            printf("%d\n", ans);
        }
    }
    return 0;
}
/* NOTES:
    - The order of children in this tree is not important. Add to first to avoid while() loop.
*/