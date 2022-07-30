/*
    Given a family tree represented by child-parent (c,p) relations in which c is a child of p. 
    Perform queries about the family tree:
        descendants <name>: return number of descendants of the given <name>
        generation <name>: return the number of generations of the descendants of the given <name>

    Note that: the total number of people in the family is less than or equal to 10^4

    Input
    Contains two blocks. The first block contains information about child-parent, including lines 
    (terminated by a line containing ***), each line contains: 
        <child> <parent> where <child> is a string represented the name of the child and 
        <parent> is a string represented the name of the parent. 
    The second block contains lines (terminated by a line containing ***), each line contains 
    two string <cmd> and <param> where 
        <cmd> is the command (which can be descendants or generation) and 
        <param> is the given name of the person participating in the query.
    Output
    Each line is the result of a corresponding query.

    Example

    Input
    Peter Newman
    Michael Thomas
    John David
    Paul Mark
    Stephan Mark
    Pierre Thomas
    Mark Newman
    Bill David
    David Newman
    Thomas Mark
    ***
    descendants Newman
    descendants Mark
    descendants David
    generation Mark
    ***

    Output
    10
    5
    2
    2
*/
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