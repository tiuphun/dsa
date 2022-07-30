/*
   Một hình chữ nhật kích thước n x m được chia thành các ô vuông con 1 x 1 với 2 màu đen hoặc trắng. Hình chữ nhật được biểu diễn bởi ma trận A(n x m) trong đó A(i, j) = 1 có nghĩa ô hàng i, cột j là ô đen và A(i, j) = 0 có nghĩa ô vuông hàng i cột j là ô trắng.
    Hãy xác định hình chữ nhật con của bảng đã cho bao gồm toàn ô đen và có diện tích lớn nhất.
    Dữ liệu
    · Dòng 1: chứa số nguyên dương n và m (1 <= n,m <= 1000)
    · Dòng i+1 (i = 1,…, n): chứa hàng thứ i của ma trận A
    Kết quả
    · Ghi ra diện tích của hình chữ nhật lớn nhất tìm được

    Ví dụ
    Dữ liệu
    4 4
    0 1 1 1
    1 1 1 0
    1 1 0 0
    1 1 1 0
    Kết quả
    6 
*/
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
    printf("%d\n",ans);
}
int main(){
    input();
    solve();
    return 0;
}
