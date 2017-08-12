#include<stdio.h>
int min(int a,int b)
{
if(a<b)
return a;
else
return b;
}
diagonalParse(int mat[4][2],int col, int row)
{
int i, j;
for(i=1;i<=row;i++)
{
for(j=1;j<=min(col,i);j++)
{
printf("%d,",mat[i-j][j-1]);
}
printf("\n");
}

for(i=1;i<=row;i++)
{
for(j=i;j<col;j++)
{
   printf("%d,",mat[row+i-j-1][j]);
}
}

}
int main()
{
int mat[4][2] = {{1,2},{3,4},{5,6},{7,8}};
diagonalParse(mat,2,4);
}
