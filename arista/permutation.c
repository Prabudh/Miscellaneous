#include<stdio.h>
void swap(char *a,char*b);
permute(char *str, int l , int r)
{
if(l==r)
{
printf("%s\n",str);
}
else
{
  for(int i =l; i<=r;i++)
  {
      swap(str+i,str+l);
      permute(str,l+1,r);
      swap(str+i,str+l);
  }
}
}
void swap(char *a, char *b)
{
char temp = *a;
*a= *b;
*b= temp;
}

void main()
{
char str[10] ;
printf("Enter string:\n");
scanf("%s",str);
permute(str, 0 , (strlen(str)-1));
}

