/*
To find if the parenthesis are balanced
*/
#include<iostream>
#include<stdio.h>
bool checkIfBalanced(char* input)
{
int i,countOpen=0,countClosed=0;
int len = strlen(input);
   for(i=0;i<len;i++)
   {
       if(countOpen>len/2)
           return false;
       if(input[i] == '(')
       {
          countOpen++;
       }  
       else if(input[i] == ')')
       {
          countClosed++;
          if(countClosed>countOpen)
             return false;
       }  
   }
   if((countOpen-countClosed) == 0)
       return true;
   else
       return false;
}
int main()
{
char *str;
printf("To find if parenthesis are balanced\n");
scanf("%s",str);
if(checkIfBalanced(str))
printf("Balanced\n");
else
printf("Not Balanced\n");
}
