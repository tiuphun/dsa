#include <stdio.h>
/*void maxSub ()
{
    smax = a[0];
    ei = a[0];
    imax = 0;
    for (int i = 1; i < (n-1); i++)
    {
        //ei = max{a[i], ei + a[i]};
        //smax = max{smax, ei};
        u = ei + a[i];
        v = a[i];
        if (u > v) ei = u;
        else ei = v;
        if (ei > smax) 
        {
            smax = ei;
            imax = i;
        }
    }
    
}
*/
int main(int argc, char const *argv[])
{
    int n; 
    printf("n = ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
        
    int smax = a[0];
    int ei = a[0];
    int imax = 0;
    int u, v;
    for (int i = 1; i < (n-1); i++)
    {
        //ei = max{a[i], ei + a[i]};
        u = ei + a[i];
        v = a[i];
        if (u > v) ei = u;
        else ei = v;
        //smax = max{smax, ei};
        if (ei > smax) 
        {
            smax = ei;
            imax = i;
        }
    }
    
    printf("Array entered: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nmaxSum = %d", smax);

    return 0;
}
