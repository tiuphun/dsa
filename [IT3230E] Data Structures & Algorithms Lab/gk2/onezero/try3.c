#include<stdio.h>
#include<string.h>

int main()
{
	int count0=0;
	int count=0;
	int count1=0;
	char string[1000000];
	scanf("%s",string);
	
	int length=strlen(string);
	for(int i=0;i<length;i++)
	{
		if(string[i]=='0')
		{
			count0++;
		}
		if(string[i]=='1')
		{
			if(count0>0)
			{
				count0=0;
				count++;
			}
		}
	}
	if(count0>0) count++;
	if(string[0]=='1'&&string[length-1]=='1') count1=count+1;
	else if(string[0]=='0'&&string[length-1]=='0') count1=count-1;
	else count1=count;
	printf("%d %d",count,count1);
}