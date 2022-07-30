#include <stdio.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
typedef struct Node treeNode;
int sum;
int OddSum(treeNode* root){
    if(root == NULL) return 0;
    else{
        if(root->data % 2 == 1) sum = sum + root->data;
        OddSum(root->left);
        OddSum(root->right);
        return sum;
    }
}
