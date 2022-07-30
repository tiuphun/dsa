#include <string.h>
#include <stdio.h>
#define N 100
char s1[N], s2[N], vb1[N], vb2[N];
int i = 0, j = 0;

int match(int i){
    if (i + strlen(s1) > strlen(vb1)) return 0;
    for (int k = 0; k < strlen(s1); k++) {
        if(s1[k] != vb1[i+k]) return 0;
    }
    return 1;
}
void replace(){
    //s1 is the to-be-replaced text, s2 new text, vb1 original, vb2 new final paragraph

    printf("\ns1 = "); 
    fgets(s1, N, stdin); 
    printf("\ns2 = "); 
    fgets(s2, N, stdin);
    printf("\nvb1 = "); 
    fgets(vb1, N, stdin);

    if(s1[strlen(s1)-1] == '\n') s1[strlen(s1)-1] = '\0';
    if(s2[strlen(s2)-1] == '\n') s2[strlen(s2)-1] = '\0';
    if(vb1[strlen(vb1)-1] == '\n') vb1[strlen(vb1)-1] = '\0';

    //printf("You entered: %s\n%s\n%s", s1, s2, vb1);

    //i - counter of vb1; j - vb2; k - s2; 
    while (i <= sizeof(vb1))
    {
        if (match(i)){
            for (int k = 0; k < strlen(s2); k++){
                vb2[j+k] = s2[k];
            }
            j = j + strlen(s2);
            i = i + strlen(s1);
        }
        else {
            vb2[j] = vb1[i]; i++; j++;
        }
    }
    //printf("\nvb2 = ");
    puts(vb2);
}

int main(int argc, char const *argv[])
{
    replace();
    return 0;
}