// m-element subsets from n-element set
#include <stdio.h>
#define SIZE 10
int n, m;
int a[SIZE];
void solution(){
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void trial(int k){
    //Sk = a(k-1)+1 ... n-m+k
    for (int y = a[k-1]+1; y < n-m+k; y++)
    {
        a[k] = y;
        if (k == m) solution();
        else trial(k+1);
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &a[i]);
    }
    trial(1);
    
    return 0;
}
