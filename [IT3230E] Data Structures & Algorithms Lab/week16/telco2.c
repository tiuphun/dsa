// Telco problem in week15, implemented in hash table + binary search tree
/* NOT DONE: WRONG (p NULL)
Write a C program to perform some queries on a telco data (comming from stdin) with the following format:
The first block of data consists of lines (terminated by a line containing #), each line is under the form: 
        call <from_number> <to_number> <date> <from_time> <end_time> 
which is a call from the phone number <from_number> to a phone number <to_number> on <date>, and starting at time-point <from_time>, terminating at time-point <end_time>
<from_number> and <to_number> are string of 10 characters (a phone number is correct if it contains only digits 0,1,...,9, otherwise, the phone number is incorrect)
<date> is under the form YYYY-MM-DD (for example 2022-10-21)
<from_time> and <to_time> are under the form hh:mm:ss (for example, 10:07:23)
 
The second block consists of queries (terminated by a line containing #), each query in a line and belongs to one of the following types:
?check_phone_number: print to stdout (in a new line) value 1 if no phone number is incorrect
?number_calls_from <phone_number>: print to stdout (in a new line) the number of times a call is made from <phone_number>
?number_total_calls: print to stdout (in a new line) the total number of calls of the data
?count_time_calls_from <phone_number>: print to stdout (in a new line) the total time duration (in seconds) the calls are made from <phone_number>

Example
Input
call 0912345678 0132465789 2022-07-12 10:30:23 10:32:00
call 0912345678 0945324545 2022-07-13 11:30:10 11:35:11
call 0132465789 0945324545 2022-07-13 11:30:23 11:32:23
call 0945324545 0912345678 2022-07-13 07:30:23 07:48:30
#
?check_phone_number
?number_calls_from 0912345678
?number_total_calls
?count_time_calls_from 0912345678
?count_time_calls_from 0132465789
#

Output
1
2
4
398
120
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
#define H 10007
#define MAX_LENGTH 100
typedef struct record
{
    char fromNumber[MAX_LENGTH];
    int call;
    int duration;
    struct record* leftChild;
    struct record* rightChild;
}node;
node* T[SIZE] = {NULL}; //the array of heads of the BST
int totalCalls;
int ansCheckNumber = 1;
int hash(char* s){
    int n = strlen(s);
    int code = 0;
    for (int i = 0; i < n; i++){
        code = (code * 256 + (s[i]-'0')) % H;
    }
    return code;
}
node* makeNode(char* fromNumber, int call, int duration){
    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->fromNumber, fromNumber);
    newNode->call = call;
    newNode->duration = duration;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}
node* findBST(node* root, char* number){
    if (root == NULL) return NULL;
    int c = strcmp(root->fromNumber, number);
    if (c == 0) return root;
    else if (c < 0) return findBST(root->rightChild, number);
    else return findBST(root->leftChild, number);
}
node* find(char* number){
    int index = hash(number);
    return findBST(T[index], number);
}   
node* insertBST(node* root, char* fromNumber, int call, int duration){
    if (root == NULL) return makeNode(fromNumber, call, duration);
    int c = strcmp(root->fromNumber, fromNumber);
    if (c == 0) return root;
    if (c < 0) root->rightChild = insertBST(root->rightChild, fromNumber, call, duration);
    else root->leftChild = insertBST(root->leftChild, fromNumber, call, duration);
    return root;
}
node* insert(char* number, int call, int duration){
    int index = hash(number);
    return insertBST(T[index], number, call, duration);
}
int convertTime(char* t){
    int hour = (t[0]-'0')*10 + (t[1] - '0');
    int min = (t[3]-'0')*10 + (t[4] - '0');
    int sec = (t[6]-'0')*10 + (t[7] - '0');
    int totalTime = hour*3600 + min*60 + sec;
    return totalTime;
}
int checkNumber(char* number){
    if(strlen(number) != 10) return 0;
    for (int i = 0; i < 10; i++) if(number[i] < '0' || number[i] > '9') return 0;
    return 1;
}
void input(){
    char fromNumber[MAX_LENGTH];
    char toNumber[MAX_LENGTH];
    char date[MAX_LENGTH];
    char startTime[MAX_LENGTH];
    char endTime[MAX_LENGTH];
    char cmd[MAX_LENGTH];
    int duration;
    
    while (1)
    {
        scanf("%s", cmd); //printf("%s\n", cmd);
        if (strcmp(cmd, "#") == 0) break;
        else if(strcmp(cmd, "call") == 0){
            scanf("%s %s %s %s %s", fromNumber, toNumber, date, startTime, endTime);
            //printf("from = %s, to = %s, date = %s, start = %s, end = %s\n", fromNumber, toNumber, date, startTime, endTime);
            duration = convertTime(endTime) - convertTime(startTime);
            node* p = find(fromNumber);
            if (p != NULL) {
                p->call++;
                p->duration += duration;
            }
            else {
                insert(fromNumber, 1, duration); 
                if (checkNumber(fromNumber) == 0 || checkNumber(toNumber) == 0) ansCheckNumber = 0;
            }
        }
    }
}
void queries(){
    char cmd[100];
    char number[11]; 
    while (1)
    {
        scanf("%s", cmd);
        if(strcmp(cmd, "#") == 0) break;
        else if(strcmp(cmd, "?check_phone_number") == 0){
            printf("%d\n", ansCheckNumber);
        }
        else if(strcmp(cmd, "?number_calls_from") == 0){
            scanf("%s", number);
            node* p = find(number);
            if (p == NULL) printf("0\n");
            else printf("%d\n", p->call);
        }
        else if(strcmp(cmd, "?number_total_calls") == 0) printf("%d\n", totalCalls);
        else if(strcmp(cmd, "?count_time_calls_from") == 0){
            scanf("%s", number);
            node* p = find(number);
            if (p == NULL) printf("0\n");
            else printf("%d\n", p->duration);
        }
    }
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    input();
    queries();
    return 0;
}

/**
 * @brief NOTES
 * Remember to printf() things out for debugging -> Did it read the input right?
 * Allocate enough memory for each read-in variables: If the size is not clear, ask the teacher right away!
 */