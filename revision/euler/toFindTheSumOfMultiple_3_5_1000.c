#include<stdio.h>

int main()
{
int i;
int noOfMultiples_3 = 1000/3;
int noOfMultiples_5 =1000/5;
int *array_3 = (int*)(malloc(sizeof(int)*noOfMultiples_3));
int *array_5 = (int *)(malloc(sizeof(int)*noOfMultiples_5));
int sum =0;
for(i=3;i<10;)
{
   array_3[i/3-1] = i;
   sum+= i;
   i=i+3;
}
for(i=5;i<10;)
{
  sum+=i;
  i=i+5;
}

printf("%d",sum);
}
