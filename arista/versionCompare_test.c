#include<stdio.h>
#include<string.h>
void compareArr1and2(int *arr1,int *arr2)
{
   for(int i=0; i<100;i++)
   {
      printf("\n %d, %d \n",*arr1, *arr2);
       if(*arr1>*arr2)
       {
           printf("Version1 is greater than version2");
           return;
       }
       else if(*arr1<*arr2)
       {
           printf("Version2 is greater than version1");
           return;
       }
       arr1++;
       arr2++; 
   }
printf("Both versions are same");
}
void compareVersion(char* arg1, char* arg2)
{
    int arr1[100]={0};
    int arr2[100]={0};
    int sum = 0;
    int j =0;
    for(int i=0;i<strlen(arg1);i++)
    {
         if(arg1[i] <='9'&& arg1[i]>='0')
             sum=sum*10+arg1[i]-'0';
         if(arg1[i] == '.')
         {
             arr1[j] = sum;
             j++;
             sum =0;
         }    
    }
    arr1[j] = sum;
    sum =0 ;j=0;
    for(int i=0;i<strlen(arg2);i++)
    {
         if(arg2[i] <='9'&& arg2[i]>='0')
             sum=sum*10+arg2[i]-'0';
         if(arg2[i] == '.')
         {
             arr2[j] = sum;
             j++;
             sum = 0;
         }    
    }
    arr2[j] = sum;
    compareArr1and2(arr1,arr2);
    
}
int main(int argc, char** argv) 
{
if(argc>2)
{
    compareVersion(argv[1],argv[2]);
}
}
