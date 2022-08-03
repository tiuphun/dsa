#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
	char ID[20];
	int patient;
	struct Node* left;
	struct Node* right;
}Node;

Node* Table[70];
int Patient_Day[70];
Node* MakeNode(char ID[],int number){
	Node* temp=(Node*)malloc(sizeof(Node));
	strcpy(temp->ID,ID);
	temp->patient=number;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

Node* Insert(Node* root,char ID[],int number){
	MakeNode(ID,number);
	if(root==NULL) return MakeNode(ID,number);
	if(strcmp(root->ID,ID)==0)	return root;
	else if(strcmp(root->ID,ID)>0){
		root->left=Insert(root->left,ID,number);
	}
	else{
		root->right=Insert(root->right,ID,number);
	}
	return root;
}

Node* Search(Node* root,char ID[]){
	if(root==NULL)	return NULL;
	if(strcmp(root->ID,ID)==0)	return root;
	else if(strcmp(root->ID,ID)>0)	return Search(root->left,ID);
	else return Search(root->right,ID);
}

int main()
{
	char cmd[100];
	int count_total_patients=0;
	while(1){
		scanf("%s",cmd);
		if(strcmp(cmd,"$Update")==0){
			char region_code[100];
			int patient;
			int day;
			scanf("%s %d %d",region_code,&day,&patient);
			count_total_patients+=patient;
			Patient_Day[day]+=patient;
			Table[day]=Insert(Table[day],region_code,patient);
		}else if(strcmp(cmd,"$CountTotalPatients")==0)	printf("%d\n",count_total_patients);
		else if(strcmp(cmd,"$FindNumberPatients")==0){
			char region_code[100];
			int day;
			scanf("%s %d",region_code,&day);
			Node* temp=Search(Table[day],region_code);
			if(temp==NULL)	printf("0\n");
			else printf("%d",temp->patient);
		}else if(strcmp(cmd,"$CountNumberPatientsOfPeriod")==0){
			int start_day;
			int end_day;
			scanf("%d %d",&start_day,&end_day);
			int total=0;
			for(int i=start_day;i<=end_day;i++){
				total+=Patient_Day[i];
			}
			printf("%d\n",total);
		}else if(strcmp(cmd,"$CountNumberPatientsOfRegion")==0){
			int total=0;
			char region_code[100];
			scanf("%s",region_code);
			for(int i=1;i<=70;i++){
				Node* p=Search(Table[i],region_code);
				if(p!=NULL) total+=p->patient;
			}
			printf("%d\n",total);
		}
		else if(strcmp(cmd,"***")==0) break;
	}
	
}
