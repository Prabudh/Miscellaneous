#include<stdio.h>
int checkThePositions(int arr[8]);
void permute(int arr[8],int index,int length,int *count);
void swap(int *ar,int i, int j)
{
int temp= ar[i];
ar[i]= ar[j];
ar[j] =temp;
}
int main()
{
int arrange[8] = {0,1,2,3,4,5,6,7};
int count=0;
permute(arrange,0,8,&count);
printf("Printing the number of ways %d\n",count);
return 1;
}
void permute(int arr[8],int index,int length,int *count) {
    if(index==length)
    {
        if(checkThePositions(arr)==1)
           (*count)++;
    }
    else
    {
        for(int i=index;i<length;i++)
        {
            swap(arr,index,i);
            permute(arr,index+1,length,count);
            swap(arr,index,i);
        }
    }

}

int checkThePositions(int arr[8])
{
   for(int i=0;i<8;i++)
      for(int j=i+1;j<8;j++)
   {
       if(((arr[j]-arr[i]) == (j-i)) || ((arr[i]-arr[j]) == (j-i)))
         return 0;
   }
return 1;
}

