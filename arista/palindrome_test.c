#include<stdio.h>
#include<string.h>
char toLower(char a)
{
return(a-'A'+'a');
}
int palindrome(char* str)
{
int i =0;
int j =strlen(str);
char a,b;
for(i=0;i<j;)
{
  if((str[i] <='Z' && str[i] >='A') || (str[i] >='a' && str[i] <='z'))
  {
     if((str[j] <='Z' && str[j] >='A') || (str[j] >='a' && str[j] <='z'))
     {
          if(str[i] <='Z' && str[i] >='A')
             a = toLower(str[i]);
          else
             a = str[i];
          if(str[j] <='Z' && str[j] >='A')
              b = toLower(str[j]);
          else
              b = str[j];

          if(a!=b)
            return 0;   
       i++;
       j--;
     }
     else
     {
         j--;
     }
  }
  else
  {
     i++;
  }
}
return 1;
}
int main()
{
char *s;
scanf("%s",s);
if(palindrome(s))
  printf("Is a Palindrome\n");
else
  printf("Is not a palindrome\n");
return 0;
}

