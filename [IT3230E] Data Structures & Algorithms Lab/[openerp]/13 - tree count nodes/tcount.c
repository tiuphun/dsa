/* 
    Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
    · MakeRoot u: Tạo ra nút gốc u của cây
    · Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v
    · CountLeaves u:  đếm và trả ra số nút lá trên cây có gốc là u 
    · CountKChildren u k: đếm và trả về số nút có đúng k nút con trên cây gốc u
    Biết rằng dữ liệu đầu vào có 1 lệnh duy nhất là MakeRoot và luôn ở dòng đầu tiên
    · Dữ liệu: bao gồm các dòng, mỗi dòng có định dạng như mô tả ở trên, trong đó dòng cuối dùng ghi * (dấu hiệu kết thúc dữ liệu)
    · Kết quả: ghi ra mỗi dòng kết quả của các lệnh CountLeaves và CountKChildren tương ứng đọc được từ đầu vào
    
    Ví dụ:
    Dữ liệu
    MakeRoot 10
    Insert 11 10
    Insert 1 10
    Insert 3 10
    Insert 5 11
    Insert 4 11
    CountLeaves 4
    CountKChildren 10 3
    Insert 8 3
    Insert 2 3
    Insert 7 3
    Insert 6 4
    Insert 9 4
    CountKChildren 10 3
    CountLeaves 10
    CountLeaves 3
    *
    Kết quả
    1
    1
    2
    7
    3
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tree
{
    int data;
    struct tree* LeftMostChild;
    struct tree* RightSibling;
}node;
node* root;
node* MakeRoot(int u){
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) return NULL;
    else{
        newNode->data = u;
        newNode->LeftMostChild = NULL;
        newNode->RightSibling = NULL;
        return newNode;
    }
}
node* find(node* root, int data){ 
    if (root == NULL) return NULL;
    if (root->data == data) return root;
    node* p = root->LeftMostChild;
    while (p != NULL) {
        node* q = find(p, data);
        if (q != NULL) return q;
        p = p->RightSibling;
    }
    return NULL;
}
node* Insert(int u, int v){
    node* p = find(root, v);
    if (p != NULL){
        if (p->LeftMostChild == NULL) {
            p->LeftMostChild = MakeRoot(u); 
            return p->LeftMostChild;
        }
        else {
            node* new = p->LeftMostChild;
            while (new->RightSibling != NULL) new = new->RightSibling;
            new->RightSibling = MakeRoot(u);
            return new->RightSibling;
        }
    }
    return NULL;
}
int CountLeaves(node* r){
    int leaves = 0;
    if (r == NULL) return 0; 
    if (r->LeftMostChild == NULL) return 1;
    for (node* p = r->LeftMostChild; p!= NULL; p = p->RightSibling){
        leaves += CountLeaves(p);
    }
    return leaves;
}
int CountKChildren(node* r, int k){
    int count = 0;
    if (r == NULL) return 0;
    int nodes = 0;
    for (node* p = r->LeftMostChild; p != NULL; p = p->RightSibling) nodes++;
    if (nodes == k) count++;
    for (node* p = r->LeftMostChild; p != NULL; p = p->RightSibling) count += CountKChildren(p, k);
    return count;
}
void traversal(node* root){
    node* p = root->LeftMostChild;
    while (p != NULL) {
        traversal(p);
        p = p->RightSibling;
    }
}
int main(int argc, char const *argv[])
{
    freopen("input.txt","r",stdin);
    char input[20]; int u, v, k;
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
        if(strcmp(input, "CountLeaves") == 0){
            scanf("%d", &u);
            node* r = find(root, u);
            int leaf = CountLeaves(r);
            printf("%d\n", leaf);
        }
        if(strcmp(input, "CountKChildren") == 0){
            scanf("%d %d", &u, &k);
            node* r = find(root, u);
            int child = CountKChildren(r, k);
            printf("%d\n", child);
        }
        if(strcmp(input, "*") == 0) break;
    }
    //traversal(root);
    return 0;
}