/*  Given a positive integer n and n positive integers a1, a2, ..., an. 
    Compute the number of positive integer solutions to the equation:
                        a1X1 + a2X2 + . . . + anXn = M

    Input
    Dòng 1: n và M
    Dòng 2: a1, a2, ..., an
    
    Output
    Số nghiệm nguyên dương

    Ví dụ
    Input
    3 5
    1 1 1

    Output
    6

    Explanation:
    5 = 1 + 1 + 3
      = 1 + 2 + 2
      = 1 + 3 + 1 
      = 2 + 1 + 2
      = 2 + 2 + 1
      = 3 + 1 + 1
*/
#include <stdio.h>
#define SIZE 100
int n, M, x[SIZE], sum = 0;

int check(int v, int k){
  if (k < n) return 1;
  return sum + v == M;
}

void solution(){
  for(int i = 1; i <= n; i++) printf("%d ", x[i]);
  printf("\n");
}

void trial(int k){
  for (int v = 1; v <= M - sum - (n-k); v++)
  {
    if (check(v, k))
    {
      x[k] = v;
      sum = sum + x[k];
      if (k == n) solution();
      else trial(k+1);
      sum = sum - x[k];
    }
    
  }
  
}

int main(int argc, char const *argv[])
{
  scanf("%d %d", &n, &M);
  trial(1);
  return 0;
}

