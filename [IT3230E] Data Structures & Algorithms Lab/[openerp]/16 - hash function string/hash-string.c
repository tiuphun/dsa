/*  DONE
    Given a string s[1…k] which is a sequence of characters taken from {‘a’, . . ., ‘z’}. 
    Given a positive integer m, the hash code of s is defined by the formula:
    H(s) =  (s[1]*256^(k-1) + s[2]*256^(k-2) + . . . + s[k]*256^0) mod m  
    (the contant integer m is a parameter)
    Given a sequence of strings k1, k2, …, kn, compute the corresponding hash codes.

    Input
    Line 1: n and m (1 <= n,m <= 100000)
    Line i+1 (i = 1,2,…,n): contains the string ki (the length of each string is less than or equal to 200)
    Output
    Each line contains the corresponding hash code of n given strings

    Example
    Input
    4 1000
    a
    ab
    abc
    abcd
    Output
    97
    930
    179
    924
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 200
int n, m, hash, k;
char s[MAX_LENGTH];
int StringHash(char* s){
    hash = 0;
    for (int i = 0; i < strlen(s); i++){
        hash = (hash * 256 + s[i])%m;
    }
    return hash;
}
int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < 4; i++)
    {
        scanf("%s", s);
        printf("%d\n", StringHash(s)); 
    }
    return 0;
}
/**
 * @brief 
 * Should NOT use power function in C "^"
 *  int p = 256^k;
    hash = (hash + s[i]*p) % m;
 */