#include <stdio.h>
typedef struct position{
    int row, col;
    int step;
}position;
typedef struct tnode{
    struct position p;
    struct tnode* next;
}node;
node* head = NULL;
node* tail = NULL;

int dr[4] = {0, 0, 1, -1}; //row
int dc[4] = {-1, 1, 0, 0}; //col
//(0,-1) = move left, (0,1) = move right...

int n, m;
int row_start, col_start;

node* makeNode(int r, int c, int step){
    node* p = (node*)malloc(sizeof(node));
    (p->position).row
}
int finalPosition(int r, int c){
    return (r<1 || r>n || c<1 || c>m); 
}
void push(int rstart, int cstart, )
void solve(){
    for
    push(row_start, col_start, 0);
    while(!queueEmpty()){
        position p = pop();
        for (int k = 0; k<4; k++){
            int new_row = p.row + dr[k];
            int new_col = p.col + dc[k];
        }
    }
}