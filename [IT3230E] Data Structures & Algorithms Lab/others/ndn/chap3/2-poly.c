#include <stdio.h>
struct PolyNode{
    int coeff;
    int pow;
    struct PolyNode* link;
};
typedef struct PolyNode Polynom;

Polynom* PolySum(Polynom* Poly1, Polynom* Poly2){
    Polynom* sum;
    for(Polynom* cur = sum; cur != NULL; cur = cur->link){
        for(Polynom* num1 = Poly1; num1 != NULL; num1 = num1->link){
            for(Polynom* num2 = Poly2; num2 != NULL; num2 = num2->link){
                if(num1->pow == num2->pow) sum->coeff = num1->coeff + num2->coeff;
            }
        }
    }
    return sum;
}