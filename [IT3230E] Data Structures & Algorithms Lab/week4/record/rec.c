#include <stdio.h>
#define N 100
#define MAX_SZ 5
typedef struct record
{
    char name[N];
    int age;
}rec;

void create(){
    char filename[N];
    printf("Input filename: "); scanf("%s", filename);
    FILE* f = fopen(filename, "wb"); //wb = write binary
    fclose(f);
}

void display(){
    char filename[N];
    printf("Input filename: "); scanf("%s", filename);
    FILE* f = fopen(filename, "rb");
    rec buffers[MAX_SZ];
    if (f == NULL) printf("Cannot open file\n");
    else {
        while (1)
        {
            int sz = fread(buffers, sizeof(rec), MAX_SZ, f);
            for (int i = 0; i < sz; i++){
                printf("\nname = %s; age = %d", buffers[i].name, buffers[i].age);
            }
            if (sz > MAX_SZ) break;
        }
    }
}

//If file does not exist, extend() create a new file! -> Check if a file exists before appending to it.
void extend(){
    char filename[N];
    printf("Input filename: "); scanf("%s", filename);
    rec r;
    if (!fopen(filename, "r")) printf ("File does not exist.\n");
    else {
        FILE* f = fopen(filename, "ab"); //ab = append binary
        if (f == NULL) printf("Cannot open file\n");
        else {
            printf("\nInput name: "); scanf("%s", &r.name);
            printf("\nInput age:"); scanf("%d", &r.age);
            int sz = fwrite(&r, sizeof(rec), 1, f);
            if (sz == 1) printf("\nSaved successfully.");
        }
    fclose(f);
    }
}
void read(){
    char filename[N];
    printf("Input filename: "); scanf("%s", filename);
    FILE* f = fopen(filename, "rb"); //rb = read binary
    if (f == NULL) printf("Cannot open file\n");
    int i; 
    printf("Input index: "); scanf("%d", &i); //0-based index
    fseek(f, sizeof(rec)*i, SEEK_SET);
    rec r;
    int sz = fread(&r, sizeof(rec), 1, f);
    if(sz == 0) printf("Cannot read the record at index %d", i);
    else printf("\nname = %s; age = %d", r.name, r.age);
    fclose(f);
}

int main(int argc, char const *argv[])
{
    int input;
    while(1){
        printf( "Choose an option:\n"
                "1. Create\n"
                "2. Display all\n"
                "3. Extend\n"
                "4. Read at\n"
                "0. Quit\n");
        scanf("%d", &input);
        switch (input)
        {
            case 1: create(); break;
            case 2: display(); break;
            case 3: extend(); break;
            case 4: read(); break;
            case 0: break;
            default: printf("Invalid option\n"); break;
        }
    }
    return 0;
}