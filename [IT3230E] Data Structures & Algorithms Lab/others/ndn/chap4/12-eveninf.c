#include <stdio.h>
struct Tnode
{
    int key;
    struct Tnode* left;
    struct Tnode* right;
};
typedef struct Tnode treeNode;
int k = 0; //counter for number of nodes with even key
int EvenLeaf(treeNode* RootTree){
    if(RootTree == NULL) return;
    else{
        if(RootTree->key % 2 == 0) k++;
        EvenLeaf(RootTree->left);
        EvenLeaf(RootTree->right);
        return k;
    } 
}