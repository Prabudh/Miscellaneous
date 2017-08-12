#include<stdio.h>
int main()
{
int mat[3][3] = {{1,2,3},
                  {4,5,6}, {7,8,9}};

for(int i = 1;i<=3;i++)
for(int j=1;j<=i;j++)
printf("%d,",mat[i-j][j-1]);

for(int i =1;i<3;i++ )
for(int j=i;j<3;j++)
printf("%d,",mat[3+i-j-1][j]);
return 1;
}
