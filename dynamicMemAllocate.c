#include <stdio.h>
//#include <alloc.h>
main() 
{
  int i,j,*p;
  printf("Enter number of students=");
  scanf("%d",&i);
  p=(int*)malloc(i*2);
  if (!p) 
      return;
  
  for (j=0;j<i;j++) {
     printf("\nEnter Marks of %d Student=",j);
     scanf("%d",(p+j));  
  }
  static int a[] = {0,1,2,3,4};
  static int *x[] = {a,a+1,a+2,a+3,a+4};
  printf ("\n %u %u %d",x,*x,*(*x));

}

