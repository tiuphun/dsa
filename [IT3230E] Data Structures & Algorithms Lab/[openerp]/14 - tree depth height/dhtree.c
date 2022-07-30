/* A - GENERAL TREE (OK)
    Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
    · MakeRoot u: Tạo ra nút gốc u của cây
    · Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v
    · Height u:  Tính và trả về độ cao của nút u
    · Depth u: Tính và trả về độ sâu của nút u
    Biết rằng dữ liệu đầu vào có 1 lệnh duy nhất là MakeRoot và luôn ở dòng đầu tiên
    · Dữ liệu: bao gồm các dòng, mỗi dòng có định dạng như mô tả ở trên, trong đó dòng cuối dùng ghi * (dấu hiệu kết thúc dữ liệu)
    · Kết quả: ghi ra mỗi dòng kết quả của các lệnh Height và Depth tương ứng đọc được từ đầu vào
    
    Ví dụ:
    Dữ liệu
    MakeRoot 10
    Insert 11 10
    Insert 1 10
    Insert 3 10
    Insert 5 11
    Insert 4 11
    Height 10
    Depth 10
    Insert 8 3
    Insert 2 3
    Insert 7 3
    Insert 6 4
    Insert 9 4
    Height 10
    Depth 10
    Depth 3
    *
    Kết quả
    3
    1
    4
    1
    2
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct tree
{
    int data;
    struct tree* leftmost_child;
    struct tree* right_sibling;
}node;
node* root;
node* MakeRoot(int u){
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {printf("Allocation failed\n"); exit(1);}
    else{
        newNode->data = u;
        newNode->leftmost_child = NULL;
        newNode->right_sibling = NULL;
    }
    return newNode;
}
node* find(int data, node* root){ 
    if (root == NULL) return NULL;
    if (root->data == data) return root;
    node* p = find(data, root->leftmost_child);
    if (p != NULL) return p;
    else {
        p = find(data, root->right_sibling); 
        return p;
    }    
}
node* Insert(int u, int v){
    node* p = find(v, root);
    if (p != NULL){
        if (p->leftmost_child == NULL) {p->leftmost_child = MakeRoot(u); return p->leftmost_child;}
        else {
            node* new = p->leftmost_child;
            while (new->right_sibling != NULL) new = new->right_sibling;
            new->right_sibling = MakeRoot(u);
            return new->right_sibling;
        }
    }
    else return NULL;
}
int Height(node* root){
    if (root == NULL) return 0;
    int tmpHeight = 0;
    node* entry = root;
    while (entry != NULL)
    {
        int h = Height(entry->leftmost_child);
        tmpHeight = tmpHeight > h ? tmpHeight : h;
        entry = entry->right_sibling;
    }
    return tmpHeight + 1;
}
int Depth(node* curNode, node* theNode, int curDep){
    if (curNode == NULL) return -1;
    if (curNode == theNode) return curDep;
    node* entry = curNode;
    int leftDepth = Depth(curNode->leftmost_child, theNode, curDep + 1);
    if (leftDepth != -1) return leftDepth;
    return Depth(curNode->right_sibling, theNode, curDep);
}
int main(int argc, char const *argv[])
{
    freopen("input.txt","r",stdin);
    char input[10]; int u, v, result;
    while(1){
        scanf("%s", input);
        if(strcmp(input, "MakeRoot") == 0){
            scanf("%d", &u); 
            root = MakeRoot(u);
        }
        if(strcmp(input, "Insert") == 0){
            scanf("%d %d", &u, &v);
            Insert(u, v);
        }
        if(strcmp(input, "Height") == 0){
            scanf("%d", &u);
            node* p = find(u, root);
            result = Height(p);
            printf("%d\n", result);
        }
        if(strcmp(input, "Depth") == 0){
            scanf("%d", &u);
            node* p = find(u, root);
            result = Depth(root, p, 1);
            printf("%d\n", result);
        }
        if(strcmp(input, "*") == 0) break;
    }
    return 0;
}
/**
 * @brief Written by Tran Anh
 * 
 */