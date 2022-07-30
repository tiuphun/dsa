#include <stdio.h>
#include <stdlib.h>
#define FIXED 10000
//Static alloc.
void demo1(){
    int a[FIXED];
    int n; 
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    int sum = 0;
    for (int i = 0; i <= n; i++) sum += a[i];
    printf("sum = %d\n", sum);
}

//Dynamic alloc.
void demo2(){
    int *a;
    int n;
    printf("input number of element: n = ");
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int)); //since a is a pointer, we need to force onto (int*)

    for (int i = 0; i < n; i++)
    {
        printf("%d element = ", i);
        scanf("%d", &a[i]);
    }

    int sum = 0;
    for (int i = 0; i <= n; i++) sum += a[i];
    printf("sum = %d\n", sum);
    printf("address of alloc. memory: %d\n", a);

    //Reallocation
    int m = n+1;
    a = (int*)realloc(a, m * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("%d element = ", i);
        scanf("%d", &a[i]);
    }

    sum = 0;
    for (int i = 0; i <= n; i++) sum += a[i];
    printf("sum = %d\n", sum);
    printf("address of alloc. memory: %d\n", a);



    free(a); //deallocate the given memory


}

//String
void demo3(){
    char *str;
    str = (char*)malloc(15);
    strcpy(str, "tutorialpoints");
    printf("string str = %s, address of str = %d\n", str, &str);
    str = (char *) realloc(str, 25);
    strcat(str, ".com");
    printf("String = %s,  Address = %u\n", str, str);

    free(str);
}
int main(int argc, char const *argv[])
{
    demo1();
    demo2();
    return 0;
}

