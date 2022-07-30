/* Giá cổ phiếu của một công ty được biễu diễn bởi dãy a1, a2, ..., an trong đó ai là giá cổ phiếu vào ngày i (i = 1, ..., n). 
Hãy giúp nhà đầu tư tìm chuỗi ngày dài nhất trong đó giá cổ phiếu luôn tăng.
Input
Dòng 1: ghi số nguyên dương n (1 <= n <= 1000000)
Dòng 2: ghi dãy số nguyên dương a1, a2,..., an (1 <= ai <= 1000000)
Output
Ghi ra độ dài của chuỗi ngày liên tiếp dài nhất trong đó giá cổ phiếu luôn tăng dần

Example
Input
5
3 1 2 7 2

Output
3
*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 0;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    int count = 0, max = 0;
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                count++;
                if (count > max) max = count;
            }
            else {
                if (count > max) max = count;
                count = 0;
            }
            i = j;
        }
        if (j == n-1) break;
        
    }
    
    max = max + 1;
    printf("%d\n", max);

    return 0;
}
