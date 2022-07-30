/* Count number of solutions to place n queens on a chess board n x n (rows and columns are indexed 1, 2, 3, ..., n) such that no two queens attack each other.

    Input
    Line 1: a positive integer n (1 <= n <= 20)
    Line 2: a positive integer K (1 <= K <= 20)
    Line k+2 (k=1, 2, ..., K): contains two integers r and c in which there is a queen in column c and row r.
    Output

    Write number of solutions found.
    Example

    Input
    5
    1
    2 1

    Output
    2
*/
#include <stdio.h>
#define MAX 9
int n, K, count = 0;
int x[MAX], a[MAX];
int check(int v, int k){
    for (int i = 1; i <= k-1; i++)
    {
        if (x[i] == v) return 0;
        if ((x[i] + i) == (v + k)) return 0;
        if ((x[i] - i) == (v - k)) return 0; 
    } 
    return 1;
}
void input(){
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) a[i] = 0;
    for (int k = 1; k <= K; k++)
    {
        int r, c;
        scanf("%d %d", &r, &c);
        a[c] = r; //positive
    }
}
void solution(){
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
}
void trial(int k){
    for (int v = (a[k] > 0 ? a[k] : 1); v <= (a[k] > 0 ? a[k] : n); v++)
    {
        if (check(v, k)) x[k] = v;
        if (k == n) count++;
        else trial(k+1);
    }
    
}
int main(int argc, char const *argv[])
{
    input();
    trial(1);
    printf("%d", count);
    
    return 0;
}
