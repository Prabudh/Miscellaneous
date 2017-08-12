//https://www.youtube.com/watch?v=NnD96abizww&index=2&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr

#include<stdio.h>
char *str1 = "helloworld";
char *str2 = "hlwzkmd";
int max(a,b) 
{
return a>b?a:b;
}
int main()
{
//create table
int n = strlen(str1);
int m = strlen(str2);
int** table = (int**)malloc(sizeof(int*)*(m+1));//num of rows

int i,j,k;
for(i=0;i<(m+1);i++)
{
table[i] = (int*)malloc(sizeof(int)*(n+1));//num of columns
}

for(i=0;i<(m+1); i++)
table[i][0] = 0;

for(j=0;j<(n+1);j++)
table[0][j]= 0;



for(i=1;i<(m+1);i++)
{
   for(j=1;j<(n+1);j++)
   {
      if(str1[j-1]==str2[i-1])
      {
          printf("%c",str1[j-1]);
          table[i][j] = table[i-1][j-1]+1;
      }
      else
      {
             table[i][j] = max(table[i-1][j],table[i][j-1]);    
      }
   }
}
for(i=0;i<m;i++)
{
 for(j=0;j<n;j++)
 {
    printf("%d ",table[i][j]);
 }
printf("\n");
} 
printf("Table[m][n] =%d\n",table[m-1][n-1]);
return 0;
}
