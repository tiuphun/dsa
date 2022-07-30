/* DONE
Mỗi nút của một cây nhị phân T có trường id (định danh của nút, id không trùng lặp nhau). 
Thực hiện chuỗi các thao tác sau đây trên cây T (ban đầu, T là cây rỗng)

MakeRoot u: tạo một nút gốc có id bằng u
AddLeft u v: tạo một nút có id = u và chèn vào vị trí con trái của nút có id bằng v trên T (không thực hiện hành động chèn nếu nút có id bằng u đã tồn tại hoặc nút có id bằng v không tồn tại hoặc nút có id bằng v đã có nút con trái rồi)
AddRight u v: tạo một nút có id = u và chèn vào vị trí con phải của nút có id bằng v trên T (không thực hiện hành động chèn nếu nút có id bằng u đã tồn tại hoặc nút có id bằng v không tồn tại hoặc nút có id bằng v đã có nút con phải rồi)
PreOrder: đưa ra trên 1 dòng mới dãy id của các nút trong phép duyệt cây T theo thứ tự trước (các phần tử cách nhau bởi đúng 1 ký tự cách SPACE)
InOrder: đưa ra trên 1 dòng mới dãy id của các nút trong phép duyệt cây T theo thứ tự giữa (các phần tử cách nhau bởi đúng 1 ký tự cách SPACE)
PostOrder: đưa ra trên 1 dòng mới dãy id của các nút trong phép duyệt cây T theo thứ tự sau (các phần tử cách nhau bởi đúng 1 ký tự cách SPACE)
 
Input
Mỗi dòng là 1 trong số cách thao tác với định dạng được mô tả ở trên (thao tác MakeRoot chỉ xuất hiện đúng 1 lần và luôn ở ngay dòng đầu tiên). 
Kết thúc của dữ liệu input là dòng chứa duy nhất ký tự *

Output
Ghi ra trên 1 dòng kết quả của 1 trong số 3 thao tác InOrder, PreOrder, PostOrder mô tả ở trên

Example
Input
MakeRoot 1
AddLeft 2 1
AddRight 3 1
AddLeft 4 3
AddRight 5 2
PreOrder
AddLeft 6 5
AddRight 7 5
InOrder
*

Output
1 2 5 3 4
2 6 5 7 1 4 3
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tree
{
    int id;
    struct tree* leftChild;
    struct tree* rightChild;
}node;
node* root;
node* MakeRoot(int u){
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {printf("Allocation failed\n"); exit(1);}
    else{
        newNode->id = u;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
    }
    return newNode;
}
node* find(int id, node* root){ //Find node by id
    if (root == NULL) return NULL;
    if (root->id == id) return root;
    node* p = find(id, root->leftChild);
    if (p != NULL) return p;
    else {
        p = find(id, root->rightChild);
        if (p != NULL) return p;
        else return NULL; //no node with such id found
    }
}
node* AddLeft(int u, int v){
    node* p = find(v, root);
    if((find(v, root) == NULL) || (find(u, root) != NULL) || p->leftChild != NULL) return NULL;
    else{
        p->leftChild = MakeRoot(u);
    }
    return p->leftChild;
}
node* AddRight(int u, int v){
    node* p = find(v, root);
    if((find(v, root) == NULL) || (find(u, root) != NULL) || p->rightChild != NULL) return NULL;
    else{
        p->rightChild = MakeRoot(u);
    }
    return p->rightChild;
}
void PreOrder(node* root){
    if(root == NULL) return;
    else{
        printf("%d ", root->id);
        PreOrder(root->leftChild);
        PreOrder(root->rightChild);
    }
}
void InOrder(node* root){
    if(root == NULL) return;
    else{
        InOrder(root->leftChild);
        printf("%d ", root->id);
        InOrder(root->rightChild);
    }
}
void PostOrder(node* root){
    if(root == NULL) return;
    else{
        PostOrder(root->leftChild);
        PostOrder(root->rightChild);
        printf("%d ", root->id);
    }
}
int main(int argc, char const *argv[])
{
    char input[10]; int u, v;
    while(1){
        scanf("%s", input);
        if(strcmp(input, "MakeRoot") == 0){
            scanf("%d", &u); 
            root = MakeRoot(u);
        }
        if(strcmp(input, "AddLeft") == 0){
            scanf("%d %d", &u, &v);
            AddLeft(u, v);
        }
        if(strcmp(input, "AddRight") == 0){
            scanf("%d %d", &u, &v);
            AddRight(u, v);
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
