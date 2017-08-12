#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *reverseACString(char *s)
{
int i =0;
char *x = (char*)(malloc(strlen(s))+1);
for(i=0;i<=strlen(s);i++)
  x[i] = s[strlen(s)-i];
return x;
}
int main()
{
char *str;
scanf("%s",str);
char *x =reverseACString(str);
for(int i= 0;i<=strlen(str);i++)
{
   printf("%c",x[i]);
}
}
