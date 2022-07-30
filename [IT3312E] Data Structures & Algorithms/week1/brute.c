#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n; 
    printf("n = ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    

    int maxSum = a[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += a[k];
            if (sum > maxSum)
                maxSum = sum;
        }
        
    }

    printf("Array entered: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nmaxSum = %d", maxSum);
    
    return 0;
}
