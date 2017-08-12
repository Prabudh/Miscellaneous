#include<stdio.h>
int array[10] = {-11,-1, 0,10,21,6,4,2,8,11};
int sum = 10;
int main()
{
    //CreateHash Table
    //Find the size of hash Table
    int min =10000;
    int max = -1101;
    int i;
    for(i=0 ; i<10; i++)
    {
        if(max<array[i])
            max = array[i];
        if(min>array[i])
            min = array[i];
    }
    int hashSize = 0;
    if(max-min > sum)
       hashSize = max-min;
    else
    {
       min = 0;
       hashSize = sum;
    }

    int * hash = (int*)(malloc(sizeof(int)* hashSize));
    
    for(i=0;i<10;i++)
    {
        hash[array[i]-min] = 1;     
    }

    for(i=0;i<10;i++)
    {
        if(hash[sum-array[i]-min]==1)
        {
             printf("\n");
             printf("%d and %d",array[i],sum-array[i]);
        }

    }

}



