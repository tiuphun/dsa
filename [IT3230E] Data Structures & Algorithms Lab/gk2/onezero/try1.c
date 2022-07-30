/* MY IDEA: FAILED *MISERABLY*
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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUG printf("zero = %d; one = %d\n", zero, one);
char S[1000];
int zero = 0, one = 0;
int main(int argc, char const *argv[])
{
    scanf("%s", S);
    int n = strlen(S);
    int flag, j;
    if(S[0] == '1' && S[1] == '0') one++; 
    if(S[n-1] == '1' && S[n-2] == '0') one++; 
    for (int i = 1; i < n; i++)
    {
        if(S[i] == '0'){
            flag = 0;
            for(j = i-1; j >= 0; j--) {
                if(S[j] == '1') flag++; 
                break;
            }
            for(j = i+1; j < n; j++) {
                if(S[j] == '1') flag++;
                break;
            }
            if(flag == 2) zero++; 
            i = j;
        }
        if(S[i] == '1'){
            flag = 0;
            for(j = i-1; j >= 0; j--) {
                if(S[j] == '0') flag++;
                break;
            }
            for(j = i+1; j < n; j++) {
                if(S[j] == '0') flag++;
                break;
            }
            if(flag == 2) one++; 
            i = j; 
        }
    }
    printf("%d %d\n", zero, one);
    return 0;
}

/**
 * NOTES
 * Increment variables are wrongly calculated.
 */