/* Given an integer n, write a program that generates all the binary sequences of length n in a lexicographic order.
Input
Line 1: contains an integer n (1 <= n <= 20)
Output
Write binary sequences in a lexicographic ordder, eac sequence in a line

Example
Input
3
Output
000
001
010
011
100
101
110
111
*/
#include <stdio.h>
#define N 100
int n;
int x[N];

int check(int v, int k){
    return 1;
}
void solution(){
    for (int i = 1; i <= n; i++){
        printf("%d", x[i]);
    }
    printf("\n");
}
void try(int k){ 
    for (int v = 0; v <=1; v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            if (k==n) solution();
            else try(k+1);
        }
    }   
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    try(1);
    return 0;
}