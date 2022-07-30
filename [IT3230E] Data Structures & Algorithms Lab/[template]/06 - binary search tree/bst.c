//Simple binary search tree implementation with only an int as record
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode
{
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* parent;
}node;
node* CreateNode(int new_key){
    node* N = (node*)malloc(sizeof(node));
    if (N == NULL) return NULL;
    else{
        N->key = new_key;
        N->left = NULL;
        N->right = NULL;
        N->parent = NULL;
    }
    return N;
}
node* search(node* root, int target){
    if(root == NULL) return NULL;
    else if(target == root->key) return root;
    else if(target <= root->key) return search(root->left);
    else if(target >= root->right) return search(root->right);
}

/* NON-RECURSIVE */
node* findMin(node* root){
    if(root == NULL) return NULL;
    else{
        for(node* p = root; p->left != NULL; p = p->left){;}
        return p;
    }
}
node* findMax(node* root){
    if(root == NULL) return NULL;
    else{
        for(node* p = root; p->right != NULL; p = p->right){;}
        return p;
    }
}
/* RECURSIVE */
node* findMin(node* root){
    if (root == NULL) return NULL;
    else{
        if(root->left == NULL) return root;
        else return findMin(root->left);
    }
}
node* findMax(node* root){
    if (root == NULL) return NULL;
    else{
        if(root->right == NULL) return root;
        else return findMax(root->right);
    }
}

node* Predecessor(node* root, node* x){
    if(x->left != NULL) return findMax(x->left);
    else{
        node* p = x->parent;
        while(p != NULL && p->right != x) {x = p; p = p->parent;}
        return p;
    }
}
node* Successor(node* root, node* x){
    if(x->right != NULL) return findMin(x->right);
    else{
        node* p = x->parent;
        while(p != NULL && p->left != x) {x = p; p = p->parent;}
        return p;
    }
}

/* NON-RECURSIVE */
node* insert(node* root, int key)
{
    if (root == NULL)
    return create_node(key);
    else if (key < root->key)
    {
        node* newNode = insert(key, root->left);
        root->left = newNode;
        newNode->parent = root; 
        return newNode;
    }
    else if (key > root->key)
    {
        node* newNode = insert(key, root->right);
        root->right = newNode;
        newNode->parent = root; 
        return newNode;
    } 
}
/* RECURSIVE */
node* insert(node* root, int key){
    if(root == NULL) {
        root = CreateNode(key); 
        return root;
    }
    if(search(root, key) == NULL){
        node* p = NULL; //p tracks the parent pointer of the new node
        if(root == NULL) {
            node* newNode = CreateNode(key);
            newNode->parent = p;
            return newNode;
        }
        p = root;
        if(key < root->key) root = root->left;
        else if(key > root->key) root = root->right;
        return insert(root, key);
    }
}


/* RECURSIVE */
node* delete(node* root, int k) { 
    node* y;
    if (root == NULL) return NULL;
    else if (k < root->key) root->left = delete(k, root->left); /* go left */ 
    else if (k > root->key) root->right = delete(k, root->right); /* go right */ 
    else /* found the node to be deleted, and pointed by root*/
    if (root->left != NULL && root->right != NULL)
    {
        /* Case 3: the replaced node is the min node of right subtree */
        y = findMin(root->right);
        root->key = y->key;
        root->right = delete(root->right, root->key);
    }
    else /*Case 1,2: have one child or no child */
    {
        y = root;
        if (root->left == NULL) root = root->right; /* only have right child or have no child */
        else if (root->right == NULL) root = root->left;/* only have left child */
        free(y);
    }
    return root;
}


/**
 * @brief 
 * Remember to add [return] before the function that get called recursively in a control path (i.e search() func)
 * Travesal is the same as basic binary tree.
 * Time complexity: O(h), h: height of the tree - for ALL of the above function
 * Average tree height: h = log(2)n
 */