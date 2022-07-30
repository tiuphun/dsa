/*
Cho văn bản T và 2 mẫu P1, P2 đều là các xâu ký tự (không chứa ký tự xuống dòng). 
Hãy thay thế các xâu P1 trong T bằng xâu P2.

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


#include <stdio.h>
#include <string.h>
#define SIZE 100
int main(int argc, char const *argv[])
{
    char p1[SIZE], p2[SIZE], t[SIZE];
    printf("\np1 = "); scanf("%[^\n]%*c", p1);
    printf("\np2 = "); scanf("%[^\n]%*c", p2);
    printf("\nT = "); scanf("%[^\n]%*c", t);

    if (strstr(t, p1) != NULL) {
        
    }
    return 0;
}
/* Documentation:
    - Câu chuyện là phải dùng tới realloc (hoặc malloc) để có thêm ô nhớ/ bớt ô nhớ khi thay thế xâu cũ bằng xâu mới
*/