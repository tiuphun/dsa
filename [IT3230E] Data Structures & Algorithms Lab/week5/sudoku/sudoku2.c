/*  Write a program to compute the number of sudoku solutions (fill the zero elements of a given partial sudoku table)

    Fill numbers from 1, 2, 3, .., 9 to 9 x 9 table so that:

    Numbers of each row are distinct
    Numbers of each column are distinct
    Numbers on each sub-square 3 x 3 are distinct

    Input
    Each line i (i = 1, 2, ..., 9) contains elements of the ith row of the Sudoku table: elements are numbers from 0 to 9 (value 0 means the empty cell of the table)
    
    Output
    The number of ways

    Example
    
    Input

    0 0 3 4 0 0 0 8 9

    0 0 6 7 8 9 0 2 3

    0 8 0 0 2 3 4 5 6

    0 0 4 0 6 5 0 9 7

    0 6 0 0 9 0 0 1 4

    0 0 7 2 0 4 3 6 5

    0 3 0 6 0 2 0 7 8

    0 0 0 0 0 0 0 0 0

    0 0 0 0 0 0 0 0 0

    Output

    64
*/

#include <stdio.h>
int x[9][9], a[9][9]; //a[] is for user input
int count = 0;
int column[9][10] = {}, row[9][10] = {}, subrec[3][3][10] = {};

int check(int v, int r, int c){
    if (row[r][v]) return 0;
    if (column[c][v]) return 0;
    if (subrec[r/3][c/3][v]) return 0;
    return 1;
}

void trial(int r, int c){

    for (int v = (a[r][c] > 0 ? a[r][c] : 1); v <= (a[r][c] > 0 ? a[r][c] : 9); v++){
        if (check(v, r, c)){
            x[r][c] = v;
            row[r][v] = 1;
            column[c][v] = 1;
            subrec[r/3][c/3][v] = 1;
            if ((r == 8) && (c == 8)) count++;
            else
            {
                if (c == 8) trial(r+1, 0);
                else trial(r, c+1);
            }
            //recovery
            row[r][v] = 0;
            column[c][v] = 0;
            subrec[r/3][c/3][v] = 0;
        }
    }
}
void input(){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}
int main(int argc, char const *argv[])
{
    input();
    trial(0,0);
    printf("%d\n", count);
    return 0;
}
