/*
    Cho văn bản T và 2 mẫu P1, P2 đều là các xâu ký tự (không chứa ký tự xuống dòng, độ dài không vượt quá 1000). Hãy thay thế các xâu P1 trong T bằng xâu P2.
    Dữ liệu
    · Dòng 1: xâu P1
    · Dòng 2: xâu P2
    · Dòng 3: văn bản T
    Kết quả:
    · Ghi văn bản T sau khi thay thế
    
    Ví dụ
    Dữ liệu
    AI
    Artificial Intelligence
    Recently, AI is a key technology. AI enable efficient operations in many fields.
    Kết quả
    Recently, Artificial Intelligence is a key technology. Artificial Intelligence enable efficient operations in many fields.
*/
#include <string.h>
#include <stdio.h>
#define N 100
char P1[N], P2[N], T[N], T2[N];
int i = 0, j = 0;

int match(int i){
    if (i + strlen(P1) > strlen(T)) return 0;
    for (int k = 0; k < strlen(P1); k++) {
        if(P1[k] != T[i+k]) return 0;
    }
    return 1;
}
void replace(){
    //P1 is the to-be-replaced text, P2 new text, T original, T2 new final paragraph
    fgets(P1, N, stdin);  
    fgets(P2, N, stdin);
    fgets(T, N, stdin);

    if(P1[strlen(P1)-1] == '\n') P1[strlen(P1)-1] = '\0';
    if(P2[strlen(P2)-1] == '\n') P2[strlen(P2)-1] = '\0';
    if(T[strlen(T)-1] == '\n') T[strlen(T)-1] = '\0';

    //i - counter of T; j - T2; k - P2; 
    while (i <= sizeof(T))
    {
        if (match(i)){
            for (int k = 0; k < strlen(P2); k++){
                T2[j+k] = P2[k];
            }
            j = j + strlen(P2);
            i = i + strlen(P1);
        }
        else {
            T2[j] = T[i]; i++; j++;
        }
    }
    puts(T2);
}

int main(int argc, char const *argv[])
{
    replace();
    return 0;
}