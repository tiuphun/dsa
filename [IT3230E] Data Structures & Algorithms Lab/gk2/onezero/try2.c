//DONE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char S[1000];
int zero = 0, one = 0;
int A0[1000]; //marking arrays
int main(int argc, char const *argv[]){
    scanf("%s", S);
    int n = strlen(S);
    int count;

    //Finding number of 0-string: Mark positions of 1's by "0"
    for (int i = 0; i < n; i++){
        if (S[i] == '1') A0[i] = 0;
        else if (S[i] == '0'){
            count = 0;
            for(int j = i+1; j <= n; j++) {
                count++;
                if(S[j] == '1') break;
            }
            A0[i] = count;
        }
        if((A0[i] > A0[i-1]) && (A0[i] > A0[i+1])) zero++;

    }
    if (S[0] == '1' && S[n-1] == '1') one = zero + 1;
    if (S[0] == '0' && S[n-1] == '0') {one = zero - 1; zero = zero - 2;}
    if ((S[0] == '1' && S[n-1] == '0') || (S[0] == '0' && S[n-1] == '1')) one = zero;
    
    
    printf("%d %d\n", zero, one);
    return 0;
}
