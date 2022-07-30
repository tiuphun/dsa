/*  Given an integer n, write a program to generate all permutations of 1, 2, ..., n in a lexicalgraphic order 
    (elements of a permutation are separated by a SPACE character).
    Input
    3

    Output
    1 2 3 
    1 3 2 
    2 1 3 
    2 3 1 
    3 1 2 
    3 2 1 
*/
#include <stdio.h>
#define N 100
int n;
int x[N];
int appear[N] = {}; //flag array, appear[v] = 1 means the value has appeared

//Idea 1: Check for sum of all elements in a permutation?
//Idea 2: Check so that no number appears twice?
//Teacher's Hint: Use an array to flagging/marking - Use Idea 2
int check(int v, int k){
    return appear[v] == 0;
}
void solution(){
    for (int i = 1; i <= n; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
}
void trial(int k){
    for (int v = 1; v <= n; v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            appear[v] = 1;
            if (k==n) solution();
            else {
                trial(k+1); 
            }
            appear[v] = 0; //recovery for the flag
        }
    }   
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    trial(1);

    return 0;
}