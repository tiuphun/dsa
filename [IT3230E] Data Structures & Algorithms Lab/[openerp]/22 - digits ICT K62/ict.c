/*  Write C program that reads an integer value N from stdin, 
    prints to stdout the number Q ways to assign values 1, 2, …, 9 to characters I, C, T, H, U, S, K 
    (characters are assigned with different values) such that:
    ICT - K62 + HUST = N

    Input
    Unique line contains an integer N (1 <= N <= 10^5)
    Output
    Write the value Q

    Hint: Use backtracking and arrays.
*/

//IDEA: Use an array for storing possible values for 7 letters: x[0]-> x[6] I-C-T-K-H-U-S
// Also use a marking array mark[] for ensuring that different letters get different values
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Q = 0, mark[11] = {}, x[11] = {};
int check(int v, int k, int N){
    if (mark[v] == 1) return 0;
    if (k < 6) return 1;
    return (x[0]*100 + x[1]*10 + x[2] - x[3]*100 - 62 + x[4]*1000 + x[5]*100 + v*10 + x[2] == N);
}
void solution(){
    Q++;
}
void trial(int k, int N){

    for (int v = 1; v <= 9; v++)
    {
        if(check(v, k, N)){
            x[k] = v;
            mark[v] = 1; 
            if(k == 6) solution();
            else trial(k+1, N);
            mark[v] = 0;
        }
    }
}
int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    trial(0, N);
    printf("%d\n", Q);
    return 0;
}
