#include <stdio.h>
#define ALPHABET 26
int i, count[ALPHABET] = {0};
char c = '\0';

int main(int argc, char const *argv[])
{
    printf("Enter some text: ");
    c = getchar();
    while (c != '\n')
    {
        if (c <= 'z' && c>= 'a')
            ++count[c - 'a'];
        c = getchar();
    }
    for (i = 0; i < ALPHABET; i++)
    {
        if (count[i] > 0)
        {
            printf("Letter '%c' appears %d times\n", 'a'+i, count[i] );
        }
        
    }
    
    return 0;
}