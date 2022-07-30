/* There are n passengers 1, 2, …, n. The passenger i want to travel from point i to point i + n (i = 1,2,…,n). 
    There is a taxi located at point 0 for transporting the passengers. 
    Given the distance matrix c(2n+1)*(2n+1) in which c(i,j) is the traveling distance from point i to point j (i, j = 0,1,…,2n) 
    Compute the shortest route for the taxi, serving n passengers and coming back to point 0 such that at any moment, 
    there is no more than one passenger in the taxi, and no point is visited more than once 
    (except for point 0, which can be visited up to twice).

    Input
    Line 1: contains n (1 ≤ n ≤ 11).
    Line i+1 (i = 1, 2,…, 2n+1) contains the ith line of the matrix c.
    Output
    Unique line contains the length of the shortest route.

    Example
    Input
    2
    0 8 5 1 10
    5 0 9 3 5
    6 6 0 8 2
    2 6 3 0 7
    2 5 3 4 0

    Output
    17
*/
#include <stdio.h>
int n, c[23][23];
void solution(){}
int check(){}
int trial(){
    for(int v = 1; v <= n; v++){
        
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i <= 2*n; i++)
    {
        for (int j = 0; j <= 2*n; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }
    
    return 0;
}
