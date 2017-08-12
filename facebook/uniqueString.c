#include<stdio.h>
#include<string.h>
char array[10][10] = {"dog","zebra","duck"};
int main()
{
int len;
int hash[26] ={0};
for(int i=0;i<3;i++)
{
len = strlen(array[i]);
for(int j=0;j<len;j++)
{
    hash[array[i][j]-'a']++;
}
}

for(int i=0;i<3;i++)
{
len = strlen(array[i]);
for(int j=0;j<len;j++)
{
    if (hash[array[i][j]-'a'] == 1)
    { 
       array[i][j+1] = '\0';
    }
}

}
for(int i=0;i<3;i++)
{
   printf("%s",array[i]);
}

return 1;
}
