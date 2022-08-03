//My idea: Hash the region code, then combined each table entry wih a binary search tree, with the sorting key is the date (day)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10007
#define MAX_LENGTH 100

typedef struct bst
{
    int day;
    char region_code[1000];
    int number_of_patients;
    struct bst* left;
    struct bst* right;
}node;
node* root[M] = {NULL}; //the array of roots of the BST
int totalPatients = 0;
int countPeriod = 0;

int hash(char* s){
    int n = strlen(s);
    int code = 0;
    for (int i = 0; i < n; i++){
        code = (code * 256 + (s[i]-'0')) % M;
    }
    return code;
}

node* makeNode(int day, char* region_code, int number_of_patients)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->day = day;
    strcpy(newNode->region_code, region_code);
    newNode->number_of_patients = number_of_patients;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* find(node* r, int day)
{
    if (r == NULL) return NULL;
    if (r->day == day) return r;
    else if (r->day > day) return find(r->left, day);
    else return find(r->right, day);
}


void Insert(node* root, int day, char* region_code, int number_of_patients)
{
    node* p = find(root, day);
    if (p != NULL) return;
    if (root == NULL)
    {
        root = makeNode(day, region_code, number_of_patients);
        return;
    }
    node* temp = root;
    while (temp != NULL)
    {
        if (temp->day > day)
        {
            if (temp->left == NULL)
            {
                temp->left = makeNode(day, region_code, number_of_patients);
                return;
            }
            temp = temp->left;
        } else
        {
            if (temp->right == NULL)
            {
                temp->right = makeNode(day, region_code, number_of_patients);
                return;
            }
            temp = temp->right;
        }
    }
}

int CountPeriod(node* root, int start_day, int end_day){
    if (root == NULL) return 0;
    if (root->day == start_day || root->day == end_day) {
        countPeriod = countPeriod + root->number_of_patients;
        return countPeriod;
    }
    else if (root->day < start_day) return CountPeriod(root->right, start_day, end_day);
    else if (root->day > end_day) return CountPeriod(root->left, start_day, end_day);
    else {
        return CountPeriod(root->right, start_day, end_day) + CountPeriod(root->left, start_day, end_day);
    }
    
}


void queries(){
    freopen("input.txt", "r", stdin);
    char cmd[100]; 
    int index;
    int day, number_of_patients, start_day, end_day;
    char region_code[1000];
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "***") == 0) break;
        else if (strcmp(cmd, "$Update") == 0){
            scanf("%s %d %d", region_code, &day, &number_of_patients);
            index = hash(region_code);
            node* p = find(root[index], day);
            if (p == NULL) {
                Insert(root[index], day, region_code, number_of_patients);
                totalPatients = totalPatients + number_of_patients;
            }
        }
        else if (strcmp(cmd, "$CountTotalPatients") == 0){
            printf("%d\n", totalPatients);
        }
        else if (strcmp(cmd, "$FindNumberPatients") == 0){
            scanf("%s %d", region_code, &day);
            index = hash(region_code);
            node* p = find(root[index], day);
            if (p != NULL) printf("%d\n", p->number_of_patients);
            else printf("0\n");
        }
        else if (strcmp(cmd, "$CountNumberPatientsOfPeriod") == 0){
            scanf("%d %d", &start_day, &end_day);
            //int result = CountPeriod(root, start_day, end_day);
            //printf("%d\n", countPeriod);
        }
        else if (strcmp(cmd, "$CountNumberPatientsOfRegion") == 0){
            scanf("%s", region_code);
        }
    }
}
int main(int argc, char const *argv[])
{
    queries();
    return 0;
}
