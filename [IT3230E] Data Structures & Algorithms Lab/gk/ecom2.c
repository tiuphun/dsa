#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int access[13] = {};
int main(int argc, char const *argv[])
{
    int year, month, date;
    char input[1000];
    while (1)
    {
        scanf("%s", input);
        if(strcmp(input, "#") == 0) break;
        month = atoi(&input[5]);
        //printf("Input = %d", month);
        if (month == 1) access[1]++;
        if (month == 2) access[2]++;
        if (month == 3) access[3]++;
        if (month == 4) access[4]++;
        if (month == 5) access[5]++;
        if (month == 6) access[6]++;
        if (month == 7) access[7]++;
        if (month == 8) access[8]++;
        if (month == 9) access[9]++;
        if (month == 10) access[10]++;
        if (month == 11) access[11]++;
        if (month == 12) access[12]++;
    }
    int Q = 0;
    for (int i = 1; i < 13; i++)
    {
        if(access[i] > Q) Q = access[i];
    }
    printf("%d\n", Q);

}