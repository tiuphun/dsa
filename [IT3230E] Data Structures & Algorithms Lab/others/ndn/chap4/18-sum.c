#include <stdio.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
typedef struct Node treeNode;
int sum;
int Sum(treeNode* root){
    if (root == NULL) return 0;
    else{
        sum = sum + root->data;
        Sum(root->left);
        Sum(root->right);
        return sum;
    }
}