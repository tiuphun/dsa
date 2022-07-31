/*
Given a string S. A 0-string is defined to be a substring of S in which all the bits of the current substring are 0 and 
the bit right-before the first bit 0 and the bit right-after the last bit 0 (if any) of the current substring are 1; 

A 1-string is defined to be a substring of S in which all the bits of the currrent substring are 1 and 
the bit right-before the first bit 1 and the bit right-after the last bit 1 (if any) of the current substring are 0.

Compute the number of 0-strings and the number of 1-strings of S.

Input
A unique line containing the string s
Output
Write the number of 0-string and the number of 1-string of s

Example
Input
100010111101101
Output
4  5
Explanation: 100010111101101 has 4 0-string (000, 0, 0, 0) and 5 1-string (1, 1, 1111, 11, 1)
*/
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