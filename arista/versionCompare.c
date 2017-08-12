#include<stdio.h>
char *version1 = "1.2.1.3.01";
char *version2 = "1.2.01.03.1";
void compare(int arr1[],int arr2[])
{
    int i;
    for(i=0;i<10;i++)
    {
        if(arr1[i] < arr2[i])
        {
            printf("%d, %d\n",arr1[i],arr2[i]);
            printf("\n1\n");
            return;
        }
        else if(arr1[i] > arr2[i])
        {
            printf("%d, %d\n",arr1[i],arr2[i]);
            printf("\n-1\n");
            return;
        }
        else 
        {

        }
    }
    printf("\n0");
}
void main() 
{
    int array1[10]={0};
    int array2[10]={0};
    int j =0;
    int sum;
    int i;
    for (i=0;i<strlen(version1);i++)
    {
      sum =0;
      while(version1[i] != '.' && version1[i] != '\0')
      {
          sum = 10*sum + (version1[i]-'0');
          i++;
      }
      array1[j] =sum;
      j++;
    }
    j=0;
    for (i=0;i<strlen(version2);i++)
    {
      sum =0;
      while(version2[i] != '.' && version2[i] != '\0')
      {
          sum = 10*sum + (version2[i]-'0');
          i++;
      }
      array2[j] =sum;
      j++;
    }
    
    compare(array1,array2);
}
