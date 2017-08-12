#include <stdio.h>
#include <stdlib.h>

void checkForDuplicate(char *str, int arr[]);
void main()
{
char array[100];
scanf("%s",array);
int alphabet[26]={0};
checkForDuplicate(array,alphabet);
}

void checkForDuplicate(char *str, int arr[])
{
  int i=0;
  char ch;
  int index;
  for(i=0;i<strlen(str);i++)
  {
     //skip spaces
     if(str[i] >= 'a' && str[i] <='z')
      {   
          index = str[i] - 'a';
          arr[index]++;
          if(arr[index] == 2)
          {
            printf("Duplicate detected\n");  
            return; 
          }
     }
     if(str[i]>='A' && str[i] <= 'Z')
     {
        index = str[i] -'A';
        arr[index]++;
        if(arr[index] ==2)
       {    printf("Duplicate detetected\n");
            return;
          } 
     }     
     
  }
  printf("No duplicate character\n");
}

