// Liệt kê xâu nhị phân không chứa 2 bit 1 đứng cạnh nhau
// try trên OpenERP trùng với từ khóa nên t đổi tên hàm thành trial()
#include <stdio.h>
#define N 100
int n;
int x[N];

int check(int v, int k){
    if (k == 1) return 1;
    else return x[k-1] + v <= 1; //eliminate the case where x[k-1] = v = 1 -> if wrong returns 0
}
void solution(){
    for (int i = 1; i <= n; i++){
        printf("%d", x[i]);
    }
    printf("\n");
}
void trial(int k){
    for (int v = 0; v <= 1; v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            if (k==n) solution();
            else trial(k+1);
        }
    }   
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    trial(1);

    return 0;
}