 #include <stdio.h>
void printCombi(char* s)
{
int n = strlen(s);
int x,j;
if(n==1)
  x=1;
else
 x = 2;
for(int i =2 ; i<=n;i++)
{
  x=x*2;
}
int bitSet = 0;
printf("%d",x);
for(int i = 0;i<x;i++)
{
  bitSet=0;
  for(j=i;j>0;)
  {
  if(j&1)
  {
     
     printf("%c",s[bitSet]);
  }
  j= j>>1;
  bitSet++;
  }
  printf("\n");
} 
}
int main()
{
char *str = "abc";
printCombi(str); 
}
