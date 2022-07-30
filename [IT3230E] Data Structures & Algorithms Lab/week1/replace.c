//Get a str, 2 chars, replace in the str 1st char w/ 2nd char
#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char s[100], c1, c2;
    gets(s); //only terminated when met '\n'
    scanf("%c %c", &c1, &c2); 
    //there should be a space between the char to be read correctly
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == c1) s[i] = c2; 
    }
    puts(s);
    
    return 0;
}