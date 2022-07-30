#include <stdio.h>
void split(double num, int *int_part, double *frac_part) {
    *int_part = (int)num;
    *frac_part = num - *int_part;
}
int main(int argc, char const *argv[])
{
    double num, fraction;
    int integer;

    printf("Enter a number: ");
    scanf("%lf", &num);

    split(num, &integer, &fraction);
    printf("%lf = %d + %lf", num, integer, fraction);
    return 0;
}