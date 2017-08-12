//https://www.youtube.com/watch?annotation_id=annotation_2195265949&feature=iv&src_vid=Y0ZqKpToTic&v=NJuKJ8sasGk

#include<iostream>
int min(int a,int b)
{
 return a<b? a:b;
}
int main()
{
int coins[] = {7,2,3,6};
int temp;
int val = 13;
int arrayOfIndices[val+1];

int array[val+1];
int i,j;
for(i=0;i<val+1;i++)
{
  array[i]= 214748364;
  arrayOfIndices[i]= -1;
}
array[0] = 0;
int k;
for(i=0;i<4;i++)
{
  for(j=1;j<val+1;j++)
  {
   if(coins[i]<=j)
   {  
      temp = array[j];
      array[j] = min(array[j],1+array[j-coins[i]]);
      if(temp>array[j])
      {
          arrayOfIndices[j]=i;
      }
   }
  }
for(k=0;k<=val;k++)
{
printf("%d ",array[k]);
//printf("%d ",arrayOfIndices[k]);
}
printf("\n");
printf("\n");
}
for(i=0;i<=val;i++)
printf("%d ",arrayOfIndices[i]);
printf("\n");
while(val!=0)
{
if(arrayOfIndices[val] !=-1)
printf("%d, ",coins[arrayOfIndices[val]]);
val -= coins[arrayOfIndices[val]];
}
printf("\n");
}
