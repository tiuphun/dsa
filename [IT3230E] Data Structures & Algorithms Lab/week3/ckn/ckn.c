#include <stdio.h>
int ckn(int k, int n){
    if (k == 0 || k == n) return 1;
    else return ckn(k-1, n-1) + ckn(k, n-1);
}