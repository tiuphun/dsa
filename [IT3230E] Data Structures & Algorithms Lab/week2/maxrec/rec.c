/*
    Một hình chữ nhật kích thước n x m được chia thành các ô vuông con 1 x 1 với 2 màu đen hoặc trắng. 
    Hình chữ nhật được biểu diễn bởi ma trận A(n x m) trong đó A(i, j) = 1 có nghĩa ô hàng i, cột j là ô đen và A(i, j) = 0 có nghĩa ô vuông hàng i cột j là ô trắng.
    Hãy xác định hình chữ nhật con của bảng đã cho bao gồm toàn ô đen và có diện tích lớn nhất.

    Dữ liệu
    · Dòng 1: chứa số nguyên dương n và m (1 <= n,m <= 50)
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
    
    Scope: 
    Chỉ tập trung vào đặt ra biến đếm và tăng cho đúng chứ chưa quan tâm tới tính tối ưu hóa.
*/
#include <stdio.h>
#define SIZE 1000

int main(int argc, char const *argv[])
{
    int m, n;
    int ans = 0;
    int A = 0;
    int a[SIZE][SIZE];

    //input
    printf("Nhap n, m: \n");
    scanf("%d %d", &n, &m);

    printf("Nhap hinh chu nhat: \n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    

    //solve
    for (int r = 1; r <= n; r++)                        //ROW
    {
        for (int c = 1; c <= m; c++)                    //COLUMN    
        {
            for (int w = 1; w <= (m-c+1); w++)            //WIDTH
            {
                for (int h = 1; h <= (r-n+1); h++)        //HEIGHT
                {
                    //AT THIS POINT WE HAVE A SUBREC
                    for (int i = r; i <= (h+r-1); i++)
                    {
                        for (int j = c; j <= (w+c-1); j++)
                        {
                            A += a[i][j];
                        }
                    }
                    if (A == w*h){ //the current subrec contains only 1 cell
                        if (ans < A) ans = A;
                    }
                }
            }
        } 
    }

    printf("%d\n", ans);
    
    return 0;
}
