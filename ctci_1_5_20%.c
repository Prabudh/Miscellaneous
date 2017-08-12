#include<stdio.h>
void replaceSpace(char *s);
void main()
{
char string[100] = "   djwegfwge wfjhberger";
printf("Enter the string");
//scanf("%s",string);
printf("%s\n", string);
//remove spaces at the beginning.

replaceSpace(string);
printf("\n%s\n",string);

}
void replaceSpace(char *s)
{ int i ;
  char str[100];
  for(i=0; i<strlen(s); i++)
  {
    if(s[i]!=' ')
      break;
  }
  strcpy(str,&s[i]);
  strcpy(s,str);

  for(i=0;i<strlen(s);i++)
  {
    //printf("I came here\n");
    //remove spaces in the beginning.
    if(s[i] == ' ')
    {
    //printf("I came here\n");
      strcpy(str,&s[i+1]);
      //printf("\n%s\n", str);
      s[i] = '%';
      i++;
      s[i] = '2';
      i++;
      s[i] = '0';
      strcpy(&s[i+1],str);
    } 
  }  
}
