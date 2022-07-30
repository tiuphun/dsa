#include <stdio.h>
#include <stdbool.h>
struct Tnode
{
    char word[20];
    struct Tnode* left;
    struct Tnode* right;
};
typedef struct Tnode BTNode;

bool isometric(BTNode* T1, BTNode* T2){
    if((T1 == NULL) && (T2 == NULL)) return true;
    if((T1 != NULL) && (T2 != NULL)){
        isometric(T1->left, T2->left);
        isometric(T1->right, T2->right);
        return true;
    }
    return false;
}
