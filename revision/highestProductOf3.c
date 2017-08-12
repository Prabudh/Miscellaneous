/*int arr[5] = {-1,-2,-3,4,5};
1.Add each number in max heap 
2. Addition of each number in max heap = logn
3. nlogn we can add all the numbers in max heap;
4. read the first 3 numbers and the product is 
*/
#include<stdio.h>
int arr[5] = {-1,-2,-3,4,5};
int max1 = ~0,max2=~0,max3=~0;
int min1=(~0>>1); min2=(~0>>1);
int length = 5;
int main()
{
for(int i=0;i<length;i++)
{
if(min1>arr[i])
{
    if(min2>arr[i])
    {
       min1 = min2;
       min2=arr[i];
    }
    else
    {
       min1= arr[i];
    }
}
if(max3<arr[i])
{
   if(max2<arr[i])
   {
       if(max1<arr[i])
       {
            max3=max2;
            max2=max1;
            max1 = arr[i];
       }
       else
       {
            max3 = max2;
            max2= arr[i];
       }
   }
   else
   {
        max3 = arr[i];
   }
}
}
printf("%d,%d,%d",max1,max2,max3);
printf("\nmin1 = %d, min2 = %d\n", min1, min2);

//Product Calc
if(max1*max2*max3 < min1*min2*max1)
{
printf("max Product =%d\n",min1*min2*max1);
}
else
{
printf("max Product =%d\n",max3*max2*max1);
}
}
