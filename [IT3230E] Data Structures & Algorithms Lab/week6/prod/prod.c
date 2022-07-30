/* Cho hai số nguyên dương a và b rất lớn (số chữ số có thể lên tới 10000). Hãy tính và in ra tích của 2 số đó.
    Input
    Dòng 1: ghi số a
    Dòng 2: ghi số b
    Output
    Ghi kết quả a*b

    Example 1
    Input
    123
    654
    Output
    80442

    Example 2
    Input
    100000000000000000
    123456789
    Output
    12345678900000000000000000

    Scope: Review array manipulation skill.
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 100
char a[N], b[N], prod[2*N];
long long ans;
void input(){
    printf("a = ");
    gets(a);
    printf("b = ");
    gets(b);
}
void multiply(){
//Multiply digit by digit, concat 0s after digit if needed.
    for (int i = strlen(a)-1; i >= 0; i--)
    {
        for (int j = strlen(b)-1; j >= 0; j--)
        {
            prod[i] = prod[i] + ((a[i]-'0') * pow(10, i) * (b[j]-'0') * pow(10, j));
        }
    }
}
void solution(){
    for (int i = 0; i < N; i++)
    {
        if(prod[i] != 0) ans = ans + prod[i];
    }
    printf("%lld", ans);
}

int main(int argc, char const *argv[])
{
    input();
    multiply();
    solution();
    return 0;
}

/* Documentation:
    - Chưa có offset - lùi chữ số sau mỗi lần lặp 
*/