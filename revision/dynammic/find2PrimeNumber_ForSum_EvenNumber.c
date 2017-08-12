//to write the optimized prime number check
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
bool isPrimeCheck(int n)
{
int isPrime[n] = 0;
for(int i=2;i<n;i++)
isPrime[i] =1;

for(int p =2;p*p<=n;p++)
{
   if(isPrime[p]==1)
   {
      for(int i =p*2;i<n;i+=p)
      {
           isPrime[i] = 0;
      }
   } 
}

return isPrime[n-1];

}
*/
/**
 * @input A : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int isPrimeCheck(int n, int* isPrime)
{
int p,i;
for( p =2;p*p<=n;p++)
{
   if(isPrime[p]==1)
   {
      for(i =p*2;i<n;i+=p)
      {
           isPrime[i] = 0;
      }
   }
}

return 1;

}

int checkPrime(int x) {
    int i;
    if(x<=1) return 0;
    int temp =sqrt(x);
    for(i=2;i<temp;i++)
    {
        if(x%i == 0) return 0;
    }
    return 1;
}
int* primesum(int A, int *len1) {
    if(A%2!=0 || A<2)
      return NULL;
    int i,j;
    int *isPrimeArray = (int*)(malloc(sizeof(int)*(A+1)));
    for(i=0;i<A+1;i++)
         isPrimeArray[i]=1;
    isPrimeArray[0] = 0;
    isPrimeArray[1] = 0;
    //len1 = (int*)(malloc(sizeof(int)));
    
    *len1 = 2;
    int *array = (int*)(malloc(sizeof(int)*2));
    array[0]=0;
    array[1]=0;
    if(isPrimeCheck(A+1,isPrimeArray)==1)
    {
        if(isPrimeArray[A]==0)
        {
        for(i=0;i<A;i++)
        {
             if(isPrimeArray[i] && isPrimeArray[A-i])
             {
               array[0]=A-i;
               array[1]=i;
             }
                
        }
        }
    }
   
    return array;
   }
int main()
{
int lenArray;
int *array = primesum(10,&lenArray);
printf("%d,%d",array[0],array[1]);
}
