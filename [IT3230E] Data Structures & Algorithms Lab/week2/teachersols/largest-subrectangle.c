#include <stdio.h>
#define N 60

int a[N][N];
int n,m;
void input(){
    scanf("%d %d",&n, &m);
    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= m; c++){
            scanf("%d", &a[r][c]);
        }
    }
}
void solve(){
    int ans = 0;
    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= m; c++){
            for(int W = 1; W <= m-c+1; W++){
                for(int H = 1; H <= n - r + 1; H++){
                    // at this point we have a sub-rectangle
                    int A = 0;
                    for(int i = r; i <= H+r-1; i++){
                        for(int j = c; j <= W+c-1; j++){
                            A += a[i][j];
                        }
                    }
                    if(A == W*H){// the current sub-rectangle contains only 1-cells
                        if(ans < A){
                            ans = A;
                        }
                    }
                }
            }
        }
    }
    printf("%d",ans);
}
int main(){
    input();
    solve();
    return 0;
}
