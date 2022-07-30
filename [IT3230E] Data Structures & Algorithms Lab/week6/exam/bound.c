#include <stdio.h>
#define MAX 100
int m, n, l[MAX], u[MAX], sum = 0;
int a[MAX];
int count;
void input(){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &l[i], &u[i]); 
    }
}

int check(int v, int k){
    if (v < l[k] || v > u[k]) return 0;
    if (k < n) return 1;
    return sum + v == m;
}

void solution(){
    //for(int i = 1; i <= n; i++) printf("%d ", a[i]);
    //printf("\n");
    count++;
}

void trial(int k){
    for (int v = 1; v <= m - sum - (n-k); v++)
    {
        if (check(v, k))
        {
            a[k] = v;
            sum = sum + a[k];
            if (k == n) solution();
            else trial(k+1);
            sum = sum - a[k];
        }
        
    }
  
}
int main(int argc, char const *argv[])
{
    input();
    trial(0);
    printf("%d\n", count);
    return 0;
}
