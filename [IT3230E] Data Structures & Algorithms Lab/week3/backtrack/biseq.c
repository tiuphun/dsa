// Liệt kê xâu nhị phân 
#include <stdio.h>
#define N 100
int n;
int x[N];

int check(int v, int k){
    return 1;
}
void solution(){
    for (int i = 1; i <= n; i++){
        printf("%d", x[i]);
    }
    printf("\n");
}
void try(int k){ 
    for (int v = 0; v <=1; v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            if (k==n) solution();
            else try(k+1);
        }
    }   
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    try(1);

    return 0;
}