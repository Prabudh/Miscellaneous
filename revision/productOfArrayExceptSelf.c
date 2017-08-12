//http://stackoverflow.com/questions/2680548/given-an-array-of-numbers-return-array-of-products-of-all-other-numbers-no-div
#include<stdio.h>
#define N 10
int array[10] = {1,2,3,4,5,6,7,8,9,10};
findProductExSelf()
{
  int productBelow[10];
  int p =1;
  int productAbove[10];

  int i;
  for(i=0; i<10;i++)
  {
    productBelow[i] = p;
    p*=array[i];
  }
  
  p = 1;
  for(i=N-1;i>=0;i--)
  {
     productAbove[i] = p;
     p*=array[i];
  }

  int product[10];
  for(i=0;i<N;i++)
  {
    product[i] = productBelow[i]*productAbove[i];
    printf("product[%d]=%d",i,product[i]);
  }

}

int main()
{
findProductExSelf();
}

