#include<stdio.h>
swap(char* a, char *b)
{
char temp = *a;
*a = *b;
*b = temp;
}
void permute(char* str,int l,int h)
{
if(l==h)
 {  printf("%s",str);
    return;
}
for(int i= l; i<=h;i++)
{
swap(str+i,str+l);
permute(str,l+1,h);
swap(str+i,str+l);
}

}
int main()
{
char *s = "abcd";
permute(s,0,strlen(s)-1);
}
