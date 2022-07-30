#include <stdio.h>
#include <string.h>
#define N 100
int palindrome(char s[], int start, int end){
    if (start >= end) return 1;
    if (s[start] == s[end]) palindrome(s, start+1, end-1);
    else return -1;
}
int main(int argc, char const *argv[])
{
    char s[N];
    fgets(s, N, stdin);
    if (palindrome(s, 0, strlen(s)) == 1) printf("Palindrome!\n");
    else printf("Not a palindrome...\n");
    return 0;
}
