#include <stdio.h>
#define N 1000
#define P 1000000007
int d[N][N];

int ckn(int k, int n){
    if (k == 0 || k == n) d[k][n] = 1;
    if (d[k][n] > 0) return (d[k][n]%P);
    else {
        d[k][n] = (ckn(k-1, n-1) + ckn(k, n-1)) % P;
        return d[k][n]%P;
    }
}
int main(int argc, char const *argv[])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            d[i][j] = 0;
        }
    }
    int k, n; 
    scanf("%d %d", &k, &n);
    printf("%d",ckn(k,n));
    return 0;
}