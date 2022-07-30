/*
Viết chương trình thực hiện công việc sau:
Xây dựng danh sách liên kết với các khóa được cung cấp ban đầu là dãy a1, a2, …, an, (đôi một khác nhau)
sau đó thực hiện các thao tác trên danh sách bao gồm: 
thêm 1 phần tử vào đầu, vào cuối danh sách, hoặc vào trước, vào sau 1 phần tử nào đó trong danh sách, 
hoặc loại bỏ 1 phần tử nào đó trong danh sách

Input
Dòng 1: ghi số nguyên dương n (1 <= n <= 1000)
Dòng 2: ghi các số nguyên dương a1, a2, …, an.
Các dòng tiếp theo lần lượt là các lệnh để thao tác (kết thúc bởi ký hiệu #) với các loại sau:
    addlast  k: thêm phần tử có key bằng k vào cuối danh sách (nếu k chưa tồn tại)
    addfirst  k: thêm phần tử có key bằng k vào đầu danh sách (nếu k chưa tồn tại)
    addafter  u  v: thêm phần tử có key bằng u vào sau phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u chưa tồn tại)
    addbefore  u  v: thêm phần tử có key bằng  u vào trước phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u của tồn tại)
    remove  k: loại bỏ phần tử có key bằng k khỏi danh sách
    reverse: đảo ngược thứ tự các phần tử của danh sách (không được cấp phát mới các phần tử, chỉ được thay đổi mối nối liên kết)

Output
Ghi ra dãy khóa của danh sách thu được sau 1 chuỗi các lệnh thao tác đã cho

Example
Input
5
5 4 3 2 1
addlast 3
addlast 10
addfirst 1
addafter 10 4
remove 1
#

Output
5 4 3 2 10 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tnode
{
    int key;
    struct tnode* next;
}node;
node* head = NULL;
//node* last; //use this to prevent traversing the whole list

node* makeNode(int x){
    node* p = (node*)malloc(sizeof(node));
    if (p == NULL)
    {
        printf("Allocation failed.\n");
        exit(1);
    }
    else {
        p->key = x; 
        p->next = NULL;
    }
    return p;
}

node* insertFirst(node* head, int x){ 
    node* new_node = makeNode(x);
    if(head == NULL) head = new_node;
    else {
        new_node->next = head;
        head = new_node;
    }
    return head;
}

node* insertAfter(node* head, node* cur, int x){
    node* new_node = makeNode(x); 
    if (head == NULL)   
    {
        head = new_node;
    }
    else{
        new_node->next = cur->next;
        cur->next = new_node;
    }
    return new_node;
}

node* insertBefore(node* head, node* cur, int x){
    node* prev = head; 
    while (prev->next != cur) prev = prev->next;
    node *new_node = makeNode(x);
    if (head == NULL) 
        head = new_node;
    else if (cur == head) { //cur is the first node in the list head = new_node;
        head = new_node;
        new_node->next = cur;
    }
    else {
        prev->next = new_node;
        new_node->next = cur;
    }
    return new_node;
}

node* insertLast(node* head, int x){
    node* new_node = makeNode(x);
    if (head == NULL) head = new_node;
    else{
        node* last = head;
        while (last->next != NULL) last = last->next;
        last->next = new_node;
    } 
    return head;
}

node* deleteNode(node* head, node* del){
    if(head == NULL) return head;
    if (head == del)
    {
        head = del->next;
        free(del);
    }
    else{
        node* prev = head;
        while (prev->next != del) prev = prev->next;
        prev->next = del->next;
        free(del);
    }
    return head;
}

void traverse(node* head){
    for(node* cur = head; cur != NULL; cur = cur->next){
        printf("%d ", cur->key);
    }
    printf("\n");
}

node* search(int x){
    for(node* cur = head; cur != NULL; cur = cur->next){
        if(cur->key == x) return cur;
    }
    return NULL; //viết cái này ở ngoài vì chỉ nên return NULL khi đã duyệt hết và không thỏa mãn
}

node* reverse(node* head){
    node* p = head;
    node* pp = NULL;
    node* np = NULL;
    while(p != NULL){
        np = p->next;
        p->next = pp;
        pp = p;
        p = np;
    }
    return pp;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    
    int key;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &key);
        head = insertLast(head, key); //phải cập nhật lại head sau mỗi vòng lặp 
    }
    //traverse(head);
    char option[100]; int u, v;
    while (1)
    {
        scanf("%s", option);
        if (strcmp(option, "addfirst") == 0){
            scanf("%d", &v);
            if(search(v) == NULL) head = insertFirst(head, v);
            //else printf("%d already existed.\n", v);
            //traverse(head);
        }
        else if(strcmp(option, "addlast") == 0){
            scanf("%d", &v);
            if(search(v) == NULL) head = insertLast(head, v);
            //
            //traverse(head);
        }
        else if(strcmp(option, "addafter") == 0){
            scanf("%d %d", &v, &u);
            node* p = search(v);
            node* q = search(u);
            if((p != NULL) && (q == NULL)) insertAfter(head, p, u);
            //traverse(head);
        }
        else if(strcmp(option, "addbefore") == 0){
            scanf("%d %d", &v, &u);
            node* p = search(v);
            node* q = search(u);
            if((p != NULL) && (q == NULL)) insertBefore(head, p, u);
            //traverse(head);
        }
        else if(strcmp(option, "remove") == 0){
            scanf("%d", &v);
            node* p = search(v);
            if (p != NULL) head = deleteNode(head, p);// **********
            //traverse(head);
        }
        else if(strcmp(option, "reverse") == 0){
            head = reverse(head);
            //traverse(head);
        }
        else if(strcmp(option, "#") == 0){
            break;
        }
    }
    traverse(head);

    return 0;
}


/* NOTES
    - Một sự khó hiểu vcl khi bộ dịch của mình cứ báo struct node* khác với node*
        -> Thầy đặt tên cho cái struct của mình là tnode, xong gòy thì tnode* next, và thế là nó không warn gì nữa luôn
    - Ở hàm insertFirst()
        if (head == NULL){head = p; last = p};
        else{last->next = p; last = p};
    - Các trường hợp đặc biệt phải xử lí:
        + Khi danh sách rỗng
        + Khi phần tử có key = u là phần tử đầu (đối với hàm duyệt các phần tử next trở đi)
    - Lỗi của t:
        + Chỉ gọi chạy hàm (vd. addFirst()) mà không gán kết quả hàm với head để cập nhật con trỏ
            -> Điều này cần thiết vì t đang viết toàn bộ hàm trả về node*, tức là truyền vào hàm theo tham số (chứ không phải tham trị)
*/
