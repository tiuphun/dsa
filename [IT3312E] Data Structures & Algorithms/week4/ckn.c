#include <stdio.h>
#define P 1000000000000
int n, k;
double time = 0;
int c(int n, int k){
    time++;
    if ((k == 0) || (k == n)) return 1;
    else return c(n-1, k-1) + c(n-1, k);
}
int main(int argc, char const *argv[])
{
    while (1)
    {
        scanf("%d %d", &n, &k);
        printf("c(%d, %d) = %d\t%d\n", n, k, c(n, k), time);
    }
    return 0;
}
