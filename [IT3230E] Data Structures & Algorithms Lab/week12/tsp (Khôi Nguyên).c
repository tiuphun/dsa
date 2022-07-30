#include<stdio.h>
#define N 30
int n;
int c[N][N]; //distance matrix
//data structures for solution modeling and backtracking search
int Cm;
int x[N];
int d;
int min_distance; //minimal distance found
int visited[N]; //visited[i]=1 means that point i has been visited
void solution()
{
    if(d+c[x[n]][x[1]]<min_distance)
    {
        min_distance=d+c[x[n]][x[1]];
    }
}
void input()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&c[i][j]);
        }
    }
}
int check(int v,int k)
{
    return visited[v]==0;
}
void Try(int k)
{
    for(int v=1;v<=n;v++)
    {
        if(check(v,k))
        {
            x[k]=v;
            visited[v]=1;
            d=d+c[x[k-1]][x[k]];
            if(k==n) solution();
            else{
                int g=d+Cm*(n-k+1);
                if(g<min_distance) Try(k+1);
            }
            visited[v]=0;
            d=d-c[x[k-1]][x[k]];

        }
    }
}
int main()
{
    input();
    for(int i=1;i<=n;i++) visited[i]=0;
    d=0;
    x[1]=1; visited[1]=1;
    min_distance=1e9;
    Try(2);
    printf("%d",min_distance);
    return 0;

}
