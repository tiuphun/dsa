/**
    Compute the sum of two integers a and b.
    
    Input
    Line 1 contains two integers a and b (0 <= a, b <= 1000000)
    Ouput
    Write the sum of a and b
    
    Example
    Input
    3 5
    Output
    8
    
*/
#include <stdio.h>
int a, b;
int main(int argc, char const *argv[])
{
    scanf("%d %d", &a, &b);
    printf("%d\n", a+b);
    return 0;
}
