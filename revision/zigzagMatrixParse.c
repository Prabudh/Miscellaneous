#include<stdio.h>
int array[3][4] = {{1,2,3,4},
                   {5,6,7,8}, 
                   {13,14,15,16}};
int min(int a , int b)
{
return a<b?a:b;
}
int main()
{
int i = 0, j=0, x=1;
for(i=1;i<=3;i++)
{
x*=-1;
  for(j=1;j<=min(3,i);j++)
  {
      if(x<0)
      printf("%d ", array[i-j][j-1]);
      if(x>0)
      printf("%d ", array[j-1][i-j]);
  }
printf("\n");
}
printf("\n");
for(i=1;i<4;i++)
{
x*= -1;
    for(j=i;j<4;j++)
    { if(x<0)
       printf("%d ",array[4+i-j-1][j]);
      if(x>0)
       printf("%d ", array[j][4+i-j-1]);
    }
 printf("\n");
}
return 0;
}
