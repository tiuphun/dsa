#include <stdio.h>
struct Tnode
{
    int key;
    struct Tnode* left;
    struct Tnode* right;
};
typedef struct Tnode treeNode;
int count; //counter for nodes with bigger key value than k
int countNodes(treeNode* RootTree, int k){
    if(RootTree == NULL) return;
    else{
        if (RootTree->key > k) count++;
        countNodes(RootTree->left, k);
        countNodes(RootTree->right, k);
        return count;
    }
}