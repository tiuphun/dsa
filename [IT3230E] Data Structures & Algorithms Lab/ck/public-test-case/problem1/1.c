//DONE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int totalTransactions = 0, totalMoney = 0;

typedef struct record
{
    char from_account[21];
    char to_account[21];
    int money;
    char time_point[9];
    char atm[11];
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
    char from_account[21], to_account[21], time_point[9], atm[11];
    int money; 
    while (1)
    {   
        scanf("%s", from_account);
        if (strcmp(from_account, "#") == 0) break;
        else{
            scanf("%s %d %s %s", to_account, &money, time_point, atm);
            //printf("from = %s, to = %s, money = %d, time = %s, atm = %s;\n", from_account, to_account, money, time_point, atm);
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
}
void queries(){
    char cmd[100];
    char from_account[21];
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
            scanf("%s", from_account);
            
        }
    }
}

int main(int argc, char const *argv[])
{
    //freopen("3-input.txt", "r", stdin);
    input(); 
    queries();
    return 0;
}
