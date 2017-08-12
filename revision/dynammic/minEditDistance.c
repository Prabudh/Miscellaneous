//https://www.youtube.com/watch?v=We3YDTzNXEk&index=8&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr
#include<stdio.h>
int mini(int a,int b)
{
return a<b?a:b;
}
int min(int a, int b, int c)
{
  return mini(a,mini(b,c));
}
int main()
{
char *str1 = "abcdef";
char *str2 = "azcdec";
int table[strlen(str2)+1][strlen(str1)+1];
int i,j;
for(i = 0; i<strlen(str2)+1;i++)
{
//Null character base case
table[i][0] = i;
}
for(i=0;i<strlen(str1)+1;i++)
{
table[0][i] = i;
}
for(i =1; i<=strlen(str2); i++)
{
for(j=1; j<=strlen(str1); j++)
{
    if(str1[j-1]!=str2[i-1])
        table[i][j] = 1+ min(table[i-1][j],table[i][j-1],table[i-1][j-1]);
    else
        table[i][j] = table[i-1][j-1];
}
}
for(i =0; i<=strlen(str2); i++)
{
for(j=0; j<=strlen(str1); j++)
{
printf("%d ",table[i][j]);
}
printf("\n");
}
printf("%d",table[strlen(str2)][strlen(str1)]);
}

