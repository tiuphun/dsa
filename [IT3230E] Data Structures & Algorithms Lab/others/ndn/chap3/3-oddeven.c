#include <stdio.h>
struct Node
{
    int Inf;
    struct Node* Next;
};
typedef struct Node LIST;
LIST* NumList;
void OddEven(){
    int count_odd = 0, count_even = 0;
    for(LIST* cur = NumList; cur != NULL; cur = cur->Next){
        if(cur->Inf % 2 == 0) count_even++;
        else count_odd++; 
    }
    printf("%d %d\n", count_even, count_odd);
}
