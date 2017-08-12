#include<stdio.h>
#include<string.h>
void swap(char *a,char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void permute(char* str,int index,int  length)
{
if(index==length)
{ printf("%s",str);
return;
}
for(int i=index;i<=length;i++)
{
    swap(str+i,str+index);
    permute(str,index+1,length);
    swap(str+i,str+index);
}
}
int main()
{
char *s="abcd";
permute(s,0,strlen(s)-1);
return 1;
}
