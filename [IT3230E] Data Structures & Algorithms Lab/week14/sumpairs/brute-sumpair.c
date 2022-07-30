/* DONE (Brute Force)
    Cho dãy a1, a2, ..., an trong đó các phần tử đôi một khác nhau và 1 giá trị nguyên dương M. 
    Hãy đếm số Q các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj = M.

    Dữ liệu
    Dòng 1: ghi n và M (1 <= n, M <= 1000000)
    Dòng 2: ghi a1, a2, ..., an
    Kết quả
    Ghi ra giá trị Q

    Ví dụ
    Dữ liệu
    5 6
    5 2 1 4 3
    Kết quả
    2
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int a[1000000], n, M, Q;
int main(int argc, char const *argv[])
{
    //freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &M);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(a[i] + a[j] == M) Q++;
        }
    }
    printf("%d\n", Q);
    return 0;
}
