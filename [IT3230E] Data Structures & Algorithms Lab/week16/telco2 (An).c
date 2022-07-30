#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define M 10000


typedef struct Node
{
    char fromNumber[20];
    int nbCalls;
    int duration;
    struct Node* leftchild;
    struct Node* rightchild;
}Node;

Node *root[M]; 

int totalCalls = 0;
int ansCheckNumber;

int h(char* s)
{
    int n = strlen(s);
    int sum = 0;
    for (int i=0; i<n; i++)
    {
        sum = (sum*256 + s[i]) % M;
    }
    return sum;
}

Node *makeNode(char*number,int _nbCalls, int _duration)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->nbCalls = _nbCalls;
    strcpy(p->fromNumber, number);
    p->duration = _duration;
    p->leftchild = NULL;
    p->rightchild = NULL;
    return p;
}
Node *insertBST(char* number, int nbCalls, int duration,Node *r)
{
    if (r==NULL)
        return makeNode(number,nbCalls, duration);
    int c = strcmp(r->fromNumber,number);
    if (c==0) return r;
    if (c<0)
        r->rightchild = insertBST(number,nbCalls,duration,r->rightchild);
    else
        r->leftchild = insertBST(number,nbCalls,duration,r->leftchild);
    return r;
}
Node *find(char* number, Node*r)
{
    if (r==NULL)
        return NULL;
    int c = strcmp(r->fromNumber,number);
    if (c==0)
        return r;
    if (c<0)
        return find(number,r->rightchild);
    else return find(number,r->leftchild);
}
int checkNumber(char *number)
{
    if (strlen(number) !=10) return 0;
    for (int i = 0; i < 10; i++)
    {
        if (number[i] < '0'|| number[i]>'9')
            return 0;
    }
    return 1;
}
int convert2Second(char *t)
{
    int h = (t[0]-'0')*10+(t[1]-'0');
    int m = (t[3]-'0')*10+(t[4]-'0');
    int s = (t[6]-'0')*10+(t[7]-'0');
    return h*3600+m*60+s;
}
void run()
{
    char fromNumber[20];
    char toNumber[20];
    char date[20];
    char fromTime[10];
    char toTime[10];
    char cmd[20];
    ansCheckNumber = 1;
    while(1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd,"#") == 0)
            break;
        else if (strcmp(cmd, "call") == 0)
        {
            scanf("%s %s %s %s %s", fromNumber,toNumber,date,fromTime,toTime);
            int duration = convert2Second(toTime) - convert2Second(fromTime);
            int index = h(fromNumber);
            Node *p = find(fromNumber,root[index]);
            if (p == NULL)
            {
                root[index] = insertBST(fromNumber,1,duration,root[index]);
            }
            else{
                p->nbCalls +=1;
                p->duration +=duration;
            }
            totalCalls+=1;
            if (checkNumber(fromNumber) == 0)
                ansCheckNumber = 0;
            if (checkNumber(toNumber) == 0)
                ansCheckNumber = 0;
        }
    }
    //read and process queries
    char number[20];
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd,"#") == 0)
            break;
        else if (strcmp(cmd,"?check_phone_number")==0)
            printf("%d\n", ansCheckNumber);
        else if (strcmp(cmd,"?number_calls_from")==0)
        {
            scanf("%s", number);
            int index = h(number);
            Node* p =find(number,root[index]);
            if(p ==NULL) printf("0\n");
            else printf("%d\n",p->nbCalls);
        }
        else if (strcmp(cmd,"?number_total_calls")==0)
            printf("%d\n", totalCalls);
        else if(strcmp(cmd,"?count_time_calls_from")==0)
        {
            scanf("%s",number);
            int index = h(number);
            Node*p=find (number, root[index]);
            if(p == NULL) printf("O\n");
            else printf("%d\n",p->duration);
        }
    }
}
int main(void)
{
    for (int i=0; i<M; i++) root[i] = NULL;
    run();
}