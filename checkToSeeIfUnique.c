#include<stdio.h>
#include<string.h>
#define true 1
#define false 0
int checkIfUnique(char *s)
{
char val;
if(strlen(s)>255)
  return false;
int compare = 0;
for(int i = 0; i<strlen(s); i++)
{
val = s[i]-'a';
if(compare & (1<<val))
    return false;
else
    compare |= 1 << val;
}  
return true;
}
int main()
{
char *str;
scanf("%s",str);
if(checkIfUnique(str)==false)
{
    printf("It has duplicate characters");
}
else{
    printf("String has all unique charaters\n");
}
return 0;
}
