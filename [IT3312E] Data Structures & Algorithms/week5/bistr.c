#include <stdio.h>
int a[100];
int n;
void solution(){
    for (int i = 1; i <= n; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    
}
void try(int k){
    //Sk = {0,1}
    for (int y = 0; y <= 1; y++) //all y in Sk
    {
        a[k] = y;
        if (k == n) solution();
        else try(k+1);
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    try(1); //determine the 1st element of the string
    return 0;
}
