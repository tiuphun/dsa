/*
Each node of a Binary Search Tree (BST) T has a key (keys of nodes must be all different).
Perform a sequence of operations on a Binary Search Tree T (starting from empty BST) including:
insert k: insert a new node having key = k into T
preorder: print (in a new line) the sequence of keys of nodes of T visited by a Pre-Order traversal (elements are separated by a SPACE character)
postorder: print (in a new line) the sequence of keys of nodes of T visited by a Post-Order traversal (elements are separated by a SPACE character)

Input
Each line contains a command of three above format
The input is terminated by a line containing #
Output
Write the information of preorder, postorder commands described above

Example
Input
insert 5
insert 9
insert 2
insert 1
preorder
insert 8
insert 5
insert 3
postorder
#

Output
5 2 1 9
1 3 2 8 9 5
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char input[20]; int u, v, k;
    while(1){
        scanf("%s", input);
        if(strcmp(input, "MakeRoot") == 0){
        }
    }
    return 0;
}
