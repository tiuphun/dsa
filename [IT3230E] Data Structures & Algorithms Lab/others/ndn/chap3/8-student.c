#include <stdio.h>
typedef struct ClassNode{
    char name[10];
    ClassNode* next;
    StudentNode* students;
}ClassNode;
typedef struct StudentNode{
    char name;
    StudentNode* next;
}StudentNode;

int NumStudents(ClassNode* ClPoint){
    int count = 0;
    for(StudentNode* cur = ClPoint->students; cur != NULL; cur = cur->next){
        count++;
    }
    return count;
}

int NumClassStudents(ClassNode* list, char* CName){
    for(ClassNode* cur = list; cur != NULL; cur = cur->next){
        if(strcmp(CName, cur->name) == 0) return NumStudents(cur);
    }
    return 0;
}