#include <stdio.h>
#include <time.h>
#define N 1000
int d[N][N] = {};

long long int ckn(int k, int n){
    if (k == 0 || k == n) d[k][n] = 1;
    if (d[k][n] > 0) return (d[k][n]);
    else {
        d[k][n] = (ckn(k-1, n-1) + ckn(k, n-1));
        return d[k][n];
    }
}
int main(int argc, char const *argv[])
{
    clock_t start, end;
    double cpu_time_used;
    int k, n; 
    scanf("%d %d", &n, &k);
    start = clock(); 
    ckn(k, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f sec\n", cpu_time_used);
    return 0;
}