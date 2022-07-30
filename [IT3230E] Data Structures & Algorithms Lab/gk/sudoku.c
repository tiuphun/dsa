#include <stdio.h>
int T;
int matrix[9][9] = {};
int result[1000] = {};
int column[9][10] = {}, row[9][10] = {}, subrec[3][3][10] = {};

int check(int v, int r, int c){
    if (row[r][v]) return 0;
    if (column[c][v]) return 0;
    if (subrec[r/3][c/3][v]) return 0;
    return 1;
}

void solve(int r, int c){
    int v = matrix[r][c];
    if(check(v, r, c)){
        row[r][v] = 1;
        column[c][v] = 1;
        subrec[r/3][c/3][v] = 1;
        if ((r == 8) && (c == 8)) result[T] = 1;
        else
        {
            if (c == 8) solve(r+1, 0);
            else solve(r, c+1);
        }
        //recovery
        row[r][v] = 0;
        column[c][v] = 0;
        subrec[r/3][c/3][v] = 0;
    }
    
}

int main(int argc, char const *argv[])
{
    scanf("%d", &T);
    for (int k = 1; k <= T; k++){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                scanf("%d", &matrix[i][j]);
            }
        }
        solve(0, 0);
    }

    for (int i = 1; i <= T; i++)
    {
        printf("%d\n", result[i]);
    }
    return 0;
}
