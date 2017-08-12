#include <stdio.h>
main()
{
int array[][2] = {
     {1,2}, {3,4},{5,6},{7,8},{9,10} 
};
int *p;
int *poi;
int (*q)[2];
p =(int *)array;
q=array;

printf("\n %ul %ul",p,q);
p++;
q++;
printf("\n %ul %ul",p,q);

int i=0,j=0;
while (i<5) {
  j=0;
  poi = q +i;
  while (j<2) {
     // printf("%d\n",array[i][j]);
     // printf("%d\n",*(array[i] + j));
     // printf("%d\n",*(*(i + array) + j));
     printf("%d ",*(poi+j)); 
     printf("%d ",*(p+i*2+j));	
     j++; 
  } 
  printf ("\n");
  i++;
}

}
