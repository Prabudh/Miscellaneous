#include<stdio.h>
#include<string.h>
#include<stdlib.h>
changeTheString(char *str)
{
int i,j,countSpace=0;
printf("%d\n",strlen(str));
for(i=0;i<strlen(str);i++)
{
    if(str[i] == ' ')
        countSpace++;
}
char *x = (char *)malloc(strlen(str)+countSpace*3);
for(i=0,j=0;i<strlen(str);i++,j++)
{
   if(str[i] == ' ')
   {
      x[j] = '%';
      j++;
      x[j] = '2';
      j++;
      x[j] = '0';
      printf("\nstr= %c, x = %c",str[i],x[j]);
   }
   else
      x[j] = str[i];

printf("\n%c",x[i]);      
}
x[j] = NULL;
printf("%s", x);
str = x;
}
int main()
{
char *str = "abcd abcde";
printf("%s",str);
changeTheString(str);
printf("%s",str);
return 0;
}
