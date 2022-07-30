#include <stdio.h>

void charReadWrite(FILE* fin, FILE* fout){
    char c;
    while((c = fgetc(fin)) != EOF){
        fputc(c,fout);
        putchar(c);
    }
}
int main(){
    char* filename1 = "result.txt";
    char* filename2 = "text.txt";
    FILE* fin = NULL;
    FILE* fout = NULL;
    if((fout = fopen(filename1, "w")) == NULL){
            printf("Cannot open file %s for writing\n",filename1);
            return 0;
    }
    if((fin = fopen(filename2,"r")) == NULL){
        printf("Cannot open file %s for reading\n", filename2);
        return 0;
    }
    charReadWrite(fin, fout);
    return 0;
}
