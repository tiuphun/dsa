typedef struct Node
{
    int data;
    struct Node* next;
}Node;
int Count(Node* ptr){
    int count = 0;
    for(Node* cur = ptr; cur->next != ptr; cur = cur->next){
        count++;
    }
    count++; //+1 since the ending node was not counted
    return count;
}
