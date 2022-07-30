#include <stdio.h>
//A leaf of a tree is a node without any child.
struct Tnode
{
    int key;
    struct Tnode* left;
    struct Tnode* right;
};
typedef struct Tnode treeNode;
int count;
int countLeaf(treeNode* RootTree){
    if(RootTree == NULL) return;
    else{
        if((RootTree->left == NULL) && (RootTree->right == NULL)) count++;
        countLeaf(RootTree->left);
        countLeaf(RootTree->right);
        return count;
    }
}