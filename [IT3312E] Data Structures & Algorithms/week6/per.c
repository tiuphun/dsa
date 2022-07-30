//Generate all permutations of n-element from 1, 2,..., n
#include <stdio.h>
#define N 100
int n, a[N];

// FIRST METHOD: USE CONDITIONAL STATEMENT
int check(int y, int k){
    //return 1 if y != a[1], a[2], ... a[k-1]
    //else return 0
    for (int j = 1; j <= k-1; j++)
    {
        if (a[j] == k) return 0;
    }
    return 1;
}

// SECOND METHOD: USE A "MARKING/ FLAGGING" ARRAY
int used[N] = {};
/* used[i] = 1 if i is already used
           = 0 otherwise
*/


void solution(){
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[n]);
    }
    printf("\n");
}
void trial(int k){
    //Sk = {1, 2, 3,..., n} \ {a[1], a[2], ... a[k-1]}

    // FIRST METHOD
    for (int y = 1; y <= n; y++)
    {
        if(check(y, k) == 1){
            a[k] = y;
            if (y == n) solution();
            else trial(k+1);
        }
    }
    
    // SECOND METHOD
    for (int y = 1; y <= n; y++)
    {
        if (used[y] == 0){
            a[k] = y; used[y] = 1;
            if (y == n) solution();
            else trial(k+1);
            used[y] = 0;
        }
    }
}

