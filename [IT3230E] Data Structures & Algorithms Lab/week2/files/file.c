//WORKING WITH FILE: An Intro
#include <stdio.h>
#define MAX_SIZE 3
void charReadWrite(FILE *fin, FILE *fout){
    char c;
    while ((c = fgetc(fin)) != EOF)
    {
        fputc(c, fout);
        putchar(c);
    }
}
void lineReadWrite(FILE *fin, FILE *fout){
    char buffer[MAX_SIZE];
    while ((fgets(buffer, MAX_SIZE, fin)) != NULL)
    {
        fputs(buffer, fout);
        printf("read buffer: %s\n", buffer);
    }
}
int main(int argc, char const *argv[])
{
    FILE *fptr1, *fptr2;
    char *filename1 = "wdemo.txt";
    char *filename2 = "rdemo.txt";
    FILE *fin = NULL;
    FILE *fout = NULL;

    if ((fout = fopen(filename1, "w")) == NULL){
        printf("Cannot open %s", filename1);
        return 0;
    }
    if ((fin = fopen(filename2, "r")) == NULL)
    {
        printf("Cannot open %s", filename2);
        return 0;
    }
    charReadWrite(fin, fout);
    lineReadWrite(fin, fout);

    fclose(fin);
    fclose(fout);
    return 0;
}
