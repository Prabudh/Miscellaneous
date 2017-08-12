#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void removeDuplicate(char *str)
{
int compare=0,j =0;
//char *x = (char*)malloc(strlen(str));
//strcpy(x,str);
char val = 0;
for(int i=0;i<strlen(str);i++)
{
val = str[i]-'a';
//printf("%c, %d\n",str[i],val);
if((compare & 1<<val))
{
for(j=i;j<strlen(str);j++)
  str[j] = str[j+1];
i=i-1;
}
else
    compare |=1<<val;
}
printf("%s\n", str);
}
int main()
{
char *str;
int x;
scanf("%s",str);

removeDuplicate(str);
printf("%s",str);
return 0;
}

