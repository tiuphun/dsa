/* WRONG
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
    struct tree* leftmost_child;
    struct tree* right_sibling;
}node;
node* root;
int total = 0, count = 0;
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
int CountLeaves(node* r){
    if(r == NULL) return 0;
    if(r->leftmost_child == NULL) return 1;
    for(node* p = r->leftmost_child; p!= NULL; p = p->right_sibling){
        total += CountLeaves(p);
    }
    return total;
}
int CountKChildren(node* r, int k){
    if(r == NULL) return 0;
    for(node* p = r->leftmost_child; p != NULL; p = p->right_sibling) count++;
    if(count == k) total++;
    for(node* p = r->leftmost_child; p != NULL; p = p->right_sibling){
        total += CountKChildren(p, k);
    }
    return total;
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
            node* r = find(u, root);
            total = 0;
            int leaf = CountLeaves(r);
            printf("%d\n", leaf);
        }
        if(strcmp(input, "CountKChildren") == 0){
            scanf("%d %d", &u, &k);
            node* r = find(u, root);
            total = 0;
            int child = CountKChildren(r, k);
            printf("%d\n", child);
        }
        if(strcmp(input, "*") == 0) break;
    }
    return 0;
}

/* NOTES:
    - Nếu muốn viết đệ quy thì tham số truyền vào phải là con trỏ, chứ số nguyên thì... ;)
        -> Nên là để đệ quy được thì thay vì CountLeaves(int u) 
        thì đành phải lấy con trỏ tới gốc u từ ngoài, rồi viết CountLeaves(node* r)
*/