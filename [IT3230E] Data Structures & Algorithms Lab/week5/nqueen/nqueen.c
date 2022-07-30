#include <stdio.h>
#define MAX 9
int n;
int x[MAX];
int check(int v, int k){
    for (int i = 1; i <= k-1; i++)
    {
        if (x[i] == v)              return 0;
        if ((x[i] + i) == (v + k))  return 0;
        if ((x[i] - i) == (v - k))  return 0; 
    }    
    return 1;
}
void solution(){
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
}
void trial(int k){
    for (int v = 1; v <= n; v++)
    {
        if (check(v, k)) x[k] = v;
        if (k == n) solution();
        else trial(k+1);
    }
    
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    trial(1);
    return 0;
}
/* Documentation:

*/