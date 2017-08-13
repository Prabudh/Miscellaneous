#include<stdio.h>
#define sum 5
int array[10] = {0,1,2,3,4,5,6,7,8,9};
int hash[10] = {0};

int main()
{
for(int i = 0;i<10;i++)
{
  hash[array[i]] = 1;
}
for(int i=0;i<10;i++)
{
  if(hash[sum-array[i]]==1)
  {
     printf("\n%d, %d",array[i],sum-array[i]);
     hash[array[i]] =0;
  }
}
} 
