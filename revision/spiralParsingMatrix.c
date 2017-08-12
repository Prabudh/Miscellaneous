#include<stdio.h>
#define M  10
#define N  5
int main()
{
int i,j,k;
int matrix[M][N];
k=1;
for(i=0;i<M;i++)
{
for(j=0;j<N;j++)
{ 
  matrix[i][j] = k;
  k++;
}
}

for(k=0;k<(M+N/2+(M+N)%2);k++)
{

i=k;
for(j=k;j<N-k;j++)
printf("%d ",matrix[i][j]);
j--;
//j=N-k-1;
for(i=k+1;i<M-k;i++)
printf("%d ", matrix[i][j]);
i--;

//i=M-k-1;
for(j=N-1-k-1;j>=k;j--)
printf("%d ", matrix[i][j]);
j++;
for(i=M-1-k-1;i>k;i--)
printf("%d ", matrix[i][j]);
i++;
}
}
/*
i=0;j=0,1,2,3(N-1)
j=3(N-1);i=0,1,2,3(M-1)
i=3(M-1);j=3(N-1),2,1,0
j=0;i=3(M-1),2,1(0+1)

i=1(0+1);j=(0+1)1,2(N-1-1)
j=2;i=1,2


1  2  3   4 2  
5  6  7   8 3  
9  10 11 12 4  
13 14 15 16 5  
17 18 19 20 6  
3  3   3 3  3

1 2 3 4
5 6 7 8 
9 1 1 2
3 4 5 6
*/
