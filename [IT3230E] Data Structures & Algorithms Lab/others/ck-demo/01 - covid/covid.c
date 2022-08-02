#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct bst
{
    int day;
    char region_code[1000];
    int number_of_patients;
    struct bst* leftChild;
    struct bst* rightChild;
}node;

void queries(){
    char cmd[100];
    int day, number_of_patients, start_day, end_day;
    char region_code[1000];
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "***") == 0) break;
        else if (strcmp(cmd, "$Update") == 0){
            scanf("%s %d %d", region_code, &day, &number_of_patients);
        }
        else if (strcmp(cmd, "$CountTotalPatients") == 0){
            
        }
        else if (strcmp(cmd, "$FindNumberPatients") == 0){
            scanf("%s %d", region_code, &day);
            
        }
        else if (strcmp(cmd, "$CountNumberPatientsOfPeriod") == 0){
            scanf("%d %d", &start_day, &end_day);
        }
        else if (strcmp(cmd, "$CountNumberPatientsOfRegion") == 0){
        }
    }
}
int main(int argc, char const *argv[])
{
    return 0;
}
