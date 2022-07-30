//The travelling salesman problem using backtracking.
/* NOT DONE
There are n cities 1, 2, ..., n. The travel distance from city i to city j is c(i,j), for i,j = 1, 2, ..., n.  
A person departs from city 1, visits each city 2, 3, ..., n exactly once and comes back to city 1. 
Find the itinerary for that person so that the total travel distance is minimal.

Input
Line 1: a positive integer n (1 <= n <= 20)
Linr i+1 (i = 1, . . ., n): contains the i-th row of the distance matrix x (elements are separated by a SPACE character)
Output
Write the total travel distance of the optimal itinerary found.

Example
Input
4
0 1 1 9
1 0 9 3
1 9 0 2
9 3 2 0
Output
7
*/

#include <stdio.h>
#define N 30
int n;                  //number of cities
int c[N][N];            //the distance matrix 
int x[N];               //the route x[1]->x[2]->x[3]->...->x[n]->x[1]
int current_dist = 0;   //accumulated distance of the route in concern
int min_dist = 0;       //minimum distance
int visited[N] = {};    //marking array for cities that has been visited
void input(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }
}
int check(int v){
    return ((visited[v] == 0) && );
}
void solution(int k){
    current_dist = current_dist + c[x[k]][x[1]];
    if (min_dist > current_dist) min_dist = current_dist;
}
void trial(int k){      // k is the k-th city in the route
    for(int v = 1; v <= n; v++){
        if(check(v)){
            x[k] = v;
            visited[v] = 1;
            current_dist = current_dist + c[x[k-1]][x[k]];
            if(k==n) solution(k);
            else{
                if (min_dist > current_dist) trial(k+1);
            }
        }
        visited[v] = 0;
        current_dist = current_dist - c[x[k-1]][x[k]];
    }
}
int main(int argc, char const *argv[])
{
    input();
    x[1] = 1; visited[1] = 1;
    trial(2);
    printf("%d\n", min_dist);
    return 0;
}
