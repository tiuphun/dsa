/* DONE
    Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây:
        MakeRoot u: Tạo ra nút gốc u của cây
        Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v
        PreOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự trước
        InOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự giữa
        PostOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự sau
    Dữ liệu: bao gồm các dòng, mỗi dòng là 1 trong số các hành động được mô tả ở trên, dòng cuối dùng là * 
    (đánh dấu sự kết thúc của dữ liệu).
    Kết quả: ghi ra trên mỗi dòng, thứ tự các nút được thăm trong phép duyệt theo thứ tự trước, giữa, sau của 
    các hành động $PreOrder, $InOrder, $PostOrder tương ứng đọc được từ dữ liệu đầu vào
    
    Ví dụ
    Dữ liệu
    MakeRoot 10
    Insert 11 10
    Insert 1 10
    Insert 3 10
    InOrder
    Insert 5 11
    Insert 4 11
    Insert 8 3
    PreOrder
    Insert 2 3
    Insert 7 3
    Insert 6 4
    Insert 9 4
    InOrder
    PostOrder
    *
    Kết quả
    11 10 1 3
    10 11 5 4 1 3 8
    5 11 6 4 9 10 1 8 3 2 7
    5 6 9 4 11 1 8 2 7 3 10
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

void PreOrder(node* root){
    if(root == NULL) return;
    printf("%d ", root->data);
    PreOrder(root->leftmost_child);
    PreOrder(root->right_sibling);
}
void InOrder(node* root){
    if(root == NULL) return;
    InOrder(root->leftmost_child);
    printf("%d ", root->data);
    if(root->leftmost_child != NULL){
        for(node* p = root->leftmost_child->right_sibling; p != NULL; p = p->right_sibling){
            InOrder(p);
        }
    }
}
void PostOrder(node* root){
    if(root == NULL) return;
    PostOrder(root->leftmost_child);
    PostOrder(root->right_sibling);
    printf("%d ", root->data);
}
int main(int argc, char const *argv[])
{
    freopen("input.txt","r",stdin);
    char input[10]; int u, v;
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
        if(strcmp(input, "PreOrder") == 0){
            PreOrder(root);
            printf("\n");
        }
        if(strcmp(input, "InOrder") == 0){
            InOrder(root);
            printf("\n");
        }
        if(strcmp(input, "PostOrder") == 0){
            PostOrder(root);
            printf("\n");
        }
        if(strcmp(input, "*") == 0) break;
    }
    return 0;
}