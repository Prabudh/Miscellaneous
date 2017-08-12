#include<stdio.h>
void reverse(char*s, int i, int j)
{
char temp;
while(i<j)
{
temp = s[i];
s[i]=s[j];
s[j]=temp;
i++;
j--;
}
}
rev(char *s)
{
   reverse(s,0,strlen(s)-1);
   int j= 0,i=0;
   for(;i<strlen(s);i++)
   {
      if(s[i]==' ')
      {
         reverse(s,j,i-1);
         j=i+1;    
      }
   }
reverse(s,j,i-1);
printf("%s",s);
}
int main()
{
char s[] = "hello abcd world";
rev(s);
int x =2;
int y=3;
x = x++ * ++y; 
y = ++x + ++y; 
printf("\n%d, %d",x,y);
struct a 
{
char s;
int b;
};
printf("%d", sizeof(struct a));
printf("\n%x", -1<<4);
return 0;
}
