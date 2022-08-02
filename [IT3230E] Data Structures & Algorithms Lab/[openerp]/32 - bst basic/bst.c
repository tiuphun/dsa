/* DONE
Each node of a Binary Search Tree (BST) T has a key (keys of nodes must be all different).
Perform a sequence of operations on a Binary Search Tree T (starting from empty BST) including:
insert k: insert a new node having key = k into T
preorder: print (in a new line) the sequence of keys of nodes of T visited by a Pre-Order traversal (elements are separated by a SPACE character)
postorder: print (in a new line) the sequence of keys of nodes of T visited by a Post-Order traversal (elements are separated by a SPACE character)

Input
Each line contains a command of three above format
The input is terminated by a line containing #
Output
Write the information of preorder, postorder commands described above

Example
Input
insert 5
insert 9
insert 2
insert 1
preorder
insert 8
insert 5
insert 3
postorder
#

Output
5 2 1 9
1 3 2 8 9 5
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct bst 
{
    int key;
    struct bst* left;
    struct bst* right;
}node;

node* root = NULL;

node* makeNode(int key)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* find(node* r, int key)
{
    if (r == NULL) return NULL;
    if (r->key == key) return r;
    node* p = find(r->left, key);
    if (p != NULL) return p;
    return find(r->right, key);
}

void Insert(int key)
{
    node* p = find(root, key);
    if (p != NULL) return;
    if (root == NULL)
    {
        root = makeNode(key);
        return;
    }
    node* temp = root;
    while (temp != NULL)
    {
        if (temp->key > key)
        {
            if (temp->left == NULL)
            {
                temp->left = makeNode(key);
                return;
            }
            temp = temp->left;
        } else
        {
            if (temp->right == NULL)
            {
                temp->right = makeNode(key);
                return;
            }
            temp = temp->right;
        }
    }
}

void PreOrder(node* r)
{
    if (r == NULL) return;
    printf("%d ", r->key);
    PreOrder(r->left);
    PreOrder(r->right);
}

void PostOrder(node* r)
{
    if (r == NULL) return;
    PostOrder(r->left);
    PostOrder(r->right);
    printf("%d ", r->key);
}


int main()
{
    freopen("input.txt", "r", stdin);
    char cmd[256] = "";
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "insert") == 0)
        {
            int key;
            scanf("%d", &key);
            Insert(key);
        }
        else if (strcmp(cmd, "preorder") == 0)
        {
            PreOrder(root);
            printf("\n");
        }
        else if (strcmp(cmd, "postorder") == 0)
        {
            PostOrder(root);
            printf("\n");
        }
        else if (strcmp(cmd, "#") == 0)
        {
            break;
        }
    }
    return 0;
}
/**
 * @brief DISCUSSION
 * Khi debug, mình thấy nếu truyền vào hàm Insert() thêm là (node* root) thì kết quả trả về hoàn toàn không có gì! (ngay cả với hàm Insert đúng của An)
 * Hàm Insert và Find trước đó mình viết sai lè -> trong phần [template], vẫn chưa sửa
 */