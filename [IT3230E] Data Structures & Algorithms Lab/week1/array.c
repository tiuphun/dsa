#include <stdio.h>
int a[1000], b[1000];
int main(){
    int t = 0;
    int m, n;
    
    // while ((t < 1) || (t > 100)){   
        scanf("%d", &t);
    //} 
    
    for (int i=1; i<=t; i++)
    {
        //printf("Nhap m, n:\n");
        scanf("%d %d", &m, &n);
        //int a[m], b[n];
        for (int j=0; j<m; j++) 
        {
            scanf("%d", &a[j]);
        }
        for (int j=0; j<n; j++) 
        {
            scanf("%d", &b[j]);
        }
        int ans;
        if (m != n) {
            ans = 0;
            printf("%d\n", ans);
        }
        else
        {
            ans = 1;
            for (int j=0; j<m; j++) {
                if (a[j] != b[j]) {
                    ans = 0; 
                    break;
                }    
            }
            printf("%d\n", ans);
        }
        

    }
}