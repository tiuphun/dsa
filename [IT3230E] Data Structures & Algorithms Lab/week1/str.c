#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char s1[] = {'a', 'x', 'b', 'c', '\0'};
    char s2[] = "abc";

    int c = strcmp(s1, s2);
    strcpy(s1, s2);
    return 0;
}