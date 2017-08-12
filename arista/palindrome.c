#include<stdio.h>
char *string = "abcd  ' ; Dcba";
//string = "bcddcb";
//string[2]= string[3];
char toLower(char x)
{
return (x-'A'+'a');
}
void convertStringToX(char *c)
{
   int i=0,j=0;
   for(i=0;i<strlen(string);i++)
   {
       if(string[i] <='Z' && string[i] >= 'A')
       {
            c[j] = toLower(string[i]);
            j++;
       }
       
       if(string[i] <= 'z' && string[i] >= 'a')
       {
           c[j] = string[i];
           j++;
       }   
   }
c[j] = '\0';
} 
void main()
{
//string[2] = string[3];
char *x;
x = (char*)(malloc(strlen(string)));
convertStringToX(x);
int i = 0;
int j = strlen(x)-1;
printf("\nx = %s\n",x);
while(i<j)
{
    if(x[i] !=x[j])
    {
        printf("Not a palindrome");
        return;
    }
i++;
j--;
}

printf("Is a palindrome");

}
