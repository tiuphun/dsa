#include <stdio.h>
#include <time.h>

int ckn(int k, int n){
    if (k == 0 || k == n) return 1;
    else return ckn(k-1, n-1) + ckn(k, n-1);
}

clock_t start, end;
double cpu_time_used;

int main(int argc, char const *argv[])
{
    int k, n;
    scanf("%d %d", &n, &k);
    start = clock(); 
    ckn(k, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f sec\n", cpu_time_used);
    return 0;
}


