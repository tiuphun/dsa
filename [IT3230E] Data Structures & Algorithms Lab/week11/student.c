#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
typedef struct student{
    char name[N];
    char email[N];
    struct student* next;
}profile;
profile* first = NULL;
profile* last = NULL;
char name[N], email[N]; 

int isEmpty(profile* first, profile* last){
    return ((first == NULL) && (last == NULL));
}

profile* makeprofile(char* name, char* email){
    profile* new_profile = (profile*)malloc(sizeof(profile));
    if (new_profile == NULL)
    {
        printf("Allocation failed.\n");
        exit(1);
    }
    else {
        strcpy(new_profile->name, name); 
        strcpy(new_profile->email, email);
        new_profile->next = NULL;
    }
    return new_profile;
}

void traverse(profile* first){
    for(profile* cur = first; cur != NULL; cur = cur->next) printf("%s\t%s\n", cur->name, cur->email);
}

profile* insertLast(profile* first, profile* last, char* name, char* email){
    profile* new_profile = makeprofile(name, email);
    if (isEmpty(first, last)){
        first = new_profile; 
        last = new_profile;
    } 
    else{
        last->next = new_profile;
        last = new_profile;
    } 
    return last;
}

profile* deleteprofile(profile* first, char* name){
    if(isEmpty(first, last)) return NULL;
    profile* cur;
    for(cur = first; cur != NULL; cur = cur->next){
        if(strcmp(cur->name, name) == 0){
            profile* del = cur;
            if(del == first){
                first = del->next;
                free(del);
            }
            else {
                profile* prev = first;
                while(prev->next != del) prev = prev->next;
                prev->next = del->next;
                free(del);
            }
        }
    }
    return cur;
}

profile* search(char* name){
    profile* cur;
    if(isEmpty(first, last)) return NULL;
    for(cur = first; cur != NULL; cur = cur->next){
        if(strcmp(cur->name, name) == 0){
            printf("%s\t%s\n", cur->name, cur->email);
            continue;
        }
    }
    return cur;
}

void load(char* filename){
    FILE* f = fopen(filename, "r");
    if (f == NULL) printf("File not found.\n");
    while (!feof(f)){
        char name[N], email[N];
        fscanf(f, "%s%s", name, email);
        insertLast(first, last, name, email);
    }
    fclose(f);
}

void save(){
    printf("Enter the filename: ");
    char filename[N];
    scanf("%s",filename);
    FILE* f = fopen(filename,"w");
    for(profile* p = first; p != NULL; p = p->next){
        fprintf(f,"%s %s",p->name,p->email); 
        if(p->next != NULL) fprintf(f,"\n");
    }
    fclose(f); 
}
int main(int argc, char const *argv[])
{
    int input = -1;
    
    char filename[N];
    while(input != 0){
        printf("\nMENU\n"
                "0. Quit\n"
                "1. Load\n"
                "2. Print\n"
                "3. Add new\n"
                "4. Remove\n"
                "5. Find profile by name\n"
                "6. Save file\n\n");
        fseek(stdin, SEEK_END, 0);
        scanf("%d", &input);
        switch (input)
        {
            case 0: break;
            case 1:
                printf("Enter filename: ");
                fseek(stdin, SEEK_END, 0);
                load(fil////ename);
                continue;
            case 2: 
                traverse(first);
                continue;
            case 3: 
                fseek(stdin, SEEK_END, 0);
                scanf("%s %s", name, email);
                insertLast(first, last, name, email);
                continue;
            case 4: 
                printf("Enter student name to remove:\n");
                fseek(stdin, SEEK_END, 0);
                scanf("%s", name);
                deleteprofile(first, name);
                continue;
            case 5: 
                printf("Enter student name to find:\n");
                fseek(stdin, SEEK_END, 0);
                scanf("%s", name);
                search(name);
                continue;
            case 6: 
                save();
                continue;
            default: 
                break;
        }
    }
    return 0;
}

/* NOTES:
    -  Chưa chạy đâu bạn ơi, chẳng thấy add mới được gì cả
*/