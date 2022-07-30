/* DONE
Given a matrix T having n rows and m columns, each element is 0 or 1. 
A column is called black column if each element on this column is 1. 
Write a program to compute the number Q of black columns.

Input
Line 1: contains two positive integers n and m (1 <= n,m <= 1000)
Line i+1 (i = 1,...,n): contains the i-th row of the matrix T

Output
Write the value of Q

Example
Input
4 4
1 0 1 0
1 1 1 0
1 0 1 1
1 1 1 1

Ouput 
2
*/
#include <stdio.h>
int m, n;
int matrix[1000][1000];
int black[1000] = {}, total = 0;

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            scanf("%d", &matrix[row][col]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        black[i] = 1;
    }
    
    for (int col = 0; col < m; col++)
    {
        for (int row = 0; row < n; row++)
        {
            if(matrix[row][col] == 0) { 
                black[col] = 0;
                break;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (black[i] == 1) total++;
    }
    
    printf("%d\n", total);
    return 0;
}
