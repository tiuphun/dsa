#include <stdio.h>
int x[9][9];
int column[9][10] = {}, row[9][10] = {}, subrec[3][3][10] = {};

int check(int v, int r, int c){
    if (row[r][v]) return 0;
    if (column[c][v]) return 0;
    if (subrec[r/3][c/3][v]) return 0;
    return 1;
}

void solution(){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------\n");
}

void trial(int r, int c){
    for (int v = 1; v <= 9; v++){
        if (check(v, r, c)){
            x[r][c] = v;
            row[r][v] = 1;
            column[c][v] = 1;
            subrec[r/3][c/3][v] = 1;
            if ((r == 8) && (c == 8)) solution();
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
int main(int argc, char const *argv[])
{
    trial(0,0);
    return 0;
}
