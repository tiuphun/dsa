#include <stdio.h>
int count = 0;
char start, end, inter;
void HanoiTower(int n, char aStart, char cEnd, char bInter){
    if(n == 1) printf("%d/ Move disk from %c to %c", count++, aStart, cEnd);
    else{
        HanoiTower(n-1, aStart, bInter, cEnd);
        HanoiTower(1, aStart, cEnd, bInter);
        HanoiTower(n-1, bInter, cEnd, aStart);
    }
}
int main(int argc, char const *argv[])
{
    HanoiTower(4, 'a', 'c', 'b');    
    return 0;
}
