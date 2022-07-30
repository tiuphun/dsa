/*
    A boss has a machine for rent. He receives a list of n orders 1, 2, ..., n: each order i consists of:
    s[i]: start day of the rent period
    e[i]: end day of the rent period
    c[i]: the revenue that the boss will get if he accepts the order i
    Compute the subset of orders that the boss accepts such that to total revenue is maximal and 
    the rent periods of two orders cannot overlap (two periods cannot have common days)

    Input
    Line 1: contains a positive integer n (1 <= n <= 40)
    Line i+1 (i = 1, 2, ..., n): contains 3 positive integer s[i], e[i], c[i] (1 <= s[i] < e[i] <= 1000, 1 <= c[i] <= 1000)
    Output
    Write the total revenue of the accepted orders

    Example
    Input
    6
    1 3 10
    3 6 10
    1 5 20
    4 9 15
    10 12 20
    6 8 20
    Output
    60
    Explanation: The boss accepts orders 3, 5, 6 with total revenue: 20 + 20 + 20 = 60
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int A[40] = {}, s[40] = {}, e[40] = {}, c[40] = {};
int n, totalRevenue, maxRevenue;
int checkOverlap(int s1, int s2, int e1, int e2){
    if(s2 >= e1 || s1 >= e2) return 1;
    else return 0;
}
int check(){
    
}
int trial(int try){
    for (int v = 0; v <= n; v++){
        if(check())
    }
}
int solve(){
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &s[i], &e[i], &c[i]);
    }
    
    printf("%d\n", totalRevenue);
    return 0;
}
