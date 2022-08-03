#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 21
int totalTransactions = 0, totalMoney = 0;

typedef struct record
{
    char from_account[LENGTH];
    char to_account[LENGTH];
    int money;
    char time_point[LENGTH];
    char atm[LENGTH];
    struct record* leftChild;
    struct record* rightChild;
}node;
node* root;

node* makeNode(char* from_account, char* to_account, int money, char* time_point, char* atm){
    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->from_account, from_account);
    strcpy(newNode->to_account, to_account);
    newNode->money = money;
    strcpy(newNode->time_point, time_point);
    strcpy(newNode->atm, atm);
    return newNode;
}
node* insert(node* root, char* from_account, char* to_account, int money, char* time_point, char* atm){
    if (root == NULL) return makeNode(from_account, to_account, money, time_point, atm);
    int c = strcmp(root->from_account, from_account);
    if (c == 0) return root;
    if (c < 0) root->rightChild = insert(root->rightChild, from_account, to_account, money, time_point, atm);
    else root->leftChild = insert(root->leftChild, from_account, to_account, money, time_point, atm);
    return root;
}
node* find(node* root, char* number){
    if (root == NULL) return NULL;
    int c = strcmp(root->from_account, number);
    if (c == 0) return root;
    else if (c < 0) return find(root->rightChild, number);
    else return find(root->leftChild, number);
}

void input(){
    char from_account[21], to_account[21], time_point[9], atm[10];
    int money; 
    while (1)
    {   
        scanf("%s %s %d %s %s", from_account, to_account, &money, time_point, atm);
        if (strcmp(from_account, "#") == 0) break;
        //printf("from = %s, to = %s, money = %d, time = %s, atm = %s\n", from_account, to_account, money, time_point, atm);
        node* p = find(root, from_account);
            if (p != NULL) {
                p->money = p->money + money;
            }
            else {
                root = insert(root, from_account, to_account, money, time_point, atm);
            }
        totalTransactions++;
        totalMoney = totalMoney + money;
    }
}
void queries(){
    char cmd[100];
    char from_account[LENGTH];
    int n;
    while (1)
    {
        scanf("%s", cmd); //printf("cmd = %s\n", cmd);
        if (strcmp(cmd, "#") == 0) break;
        else if (strcmp(cmd, "?number_transactions") == 0){
            printf("%d\n", totalTransactions);
        }
        else if (strcmp(cmd, "?total_money_transaction") == 0){
            printf("%d\n", totalMoney);
        }
        else if (strcmp(cmd, "?list_sorted_accounts") == 0){
            
        }
        else if (strcmp(cmd, "?total_money_transaction_from") == 0){
            scanf("%s", from_account);
            node* p = find(root, from_account);
            if (p != NULL) printf("%d\n", p->money);
        }
        else if (strcmp(cmd, "?inspect_cycle") == 0){
            scanf("%s %d", from_account, &n);
            
        }
    }
}

int main(int argc, char const *argv[])
{
    input(); 
    queries();
    return 0;
}

/**
 * Nguyễn Tiểu Phương 20210692 (Class: 131140)
 * NOTE: Chương trình của em gặp một lỗi lạ, đó là luôn skip mất một dòng của đầu vào sau khi đọc hàm input().
 * Tức là hàm queries() luôn chỉ đọc dòng cuối cùng chứa dấu "#", do đó không chạy thêm gì nữa.
 * (Dòng chứa lệnh tương ứng của queries() trong các bài chính là dòng bị bỏ qua, nên output sai)
 * Nếu input thủ công bằng tay thì kết quả ra đúng, mặc dù vẫn skip mất một dòng (tức phải gõ câu queries 2 lần thì mới ra kết quả).
 */
