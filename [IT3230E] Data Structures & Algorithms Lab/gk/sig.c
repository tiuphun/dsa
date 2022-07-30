/*

*/
#include <stdio.h>
int a[1000000];
int n, Q;
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n-1; i++)
    {
        if((a[i] > a[i-1]) && (a[i] > a[i+1])) Q++;
    }
    printf("%d\n", Q);
    
    return 0;
}
