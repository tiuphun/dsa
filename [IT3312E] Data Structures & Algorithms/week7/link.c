typedef struct{
    char * name;
    char * telephone;
}student;
typedef struct 
{
    student data;
    struct node *next;
}node;
//access a certain field of an element: use a temporary pointer
node *newNode = (node *) malloc(sizeof(node));
newNode->student.name;
//delete/free after use
free(newNode);    