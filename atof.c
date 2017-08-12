#include<stdio.h>
double atof(char* s);
int isdigit(char c);
void main()
{
  char a[10];
  char *s = a;
  printf("Enter the string to be converted to float.\n");
  scanf("%s",s);
  double x = atof(s);
  printf("\n%f\n",x);
}

double atof(char* s)
{
  double test = 0;
  int sign = 1;
  int i = 0;
  for(;s[i]==' ';i++)
    ;
  if(s[i] == '-')
  {
    i++;
    sign = -1;
  }

  for(;(i<strlen(s)) && (isdigit(s[i]));i++)
    {    
    test= test*10 + s[i]-'0';
    }  
  if(s[i]=='.')
  {
    i++;
    int pow= 1;
    for(;(i<strlen(s)) && (isdigit(s[i]));i++)
    {
       test= test*10 + s[i]-'0';
       pow= pow*10;
    }
    test = test/pow;
  }
  test = test*sign;
  return test;
}

int isdigit(char c)
{
  if(c<='9' && c>='0')
  {
    return 1;  
  }

  return 0;
}
