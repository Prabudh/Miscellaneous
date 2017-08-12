#include<stdio.h>
int a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

void zigzag(int x[3][4])
{
int i , j;
for(i = 0; i<3; i++)
{
if(i%2)
{
for(j=0; j<4;j++)
{
printf("%d ",x[i][j]);
}
}
else
{
for(j=3; j>=0;j--)
{
printf("%d ",x[i][j]);
}
}
printf("\n");
}
}
int main()
{
zigzag(a);
return 0;
}
