//https://www.youtube.com/watch?v=RUB5ZPfKcnY&index=42&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr
#include<stdio.h>
int main()
{
int N= 10;
int a;
printf("Enter the number of elements in the preorder sequence of binary tree.");
scanf("%d",&a);
int T[10] = {0};
T[0] = 1;
T[1] = 1;
for(int i=2;i<=a;i++)
{
   for(int j= 0;j<i;j++)
   { 
      T[i] += T[j]*T[i-j-1]; 
   }  
}
printf("%d",T[a]);
return T[a];
}
