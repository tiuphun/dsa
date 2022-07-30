#include <stdio.h>
int S[];
// The set S contains elements index S[0], S[1], ... S[n-1]
int isSubSum(int S[], int n, int sum){
    if (sum == 0) return 1;
    if ((n == 0) & (sum > 0)) return 0;
    if (sum < S[n-1]) //S' doesn't contain last element S[n-1]
        return isSubsetSum(S, n-1, sum);
    else return isSubsetSum(S, n-1, sum) || isSubsetSum(S, n-1, sum - S[n-1]);
}

// HINT:
/* if S' contain last element of S
    return isSubsetSum(S, n-1, sum - S[n-1])
if S' does not contain
    return isSubsetSum(S, n-1, sum)
base case:
1) n == 0, sum > 0 -> return false;
2) sum == 0        -> return true;
*/ 