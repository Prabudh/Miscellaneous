//https://www.youtube.com/watch?v=s6FhG--P7z0&index=4&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr
#include"stdio.h"
#include<iostream>
using namespace std;
//Subset sum problem 
int main()
{
    int arrNum[5] = {2,3,7,8,10};
    int val,i,j;
    scanf("%d",&val);
    int row = sizeof(arrNum)/sizeof(arrNum[0])+1;
    bool table[row][val+1];
    int col= val+1; 
    int *Num = (int*)malloc(sizeof(int)*(col));
    for(i=0;i<col;i++)
    {
       Num[i] = i;
       table[0][i] = false;
    }
    
    for(i=0;i<row;i++)
    {
        table[i][0] = true;
    }
    
    for(i=1;i<row;i++)
    {
    for(j=1;j<(val+1);j++)
    {
    if(arrNum[i-1]>j)
    {
         table[i][j] = table[i-1][j];
    }
    else
    {
         table[i][j] = table[i-1][j] || table[i-1][(j-arrNum[(i-1)])];
         if(arrNum[i-1]==3 && j == 5)
         {
             printf("%d\n",table[i][j]);
         } 
    }
    }
    }
    
    for(i=0;i<row;i++)
    {
     for(j=0;j<col;j++)
    {
        printf("%d ",table[i][j]);
    }
    printf("\n");
    }
   if(table[row-1][val])
   {
      printf("Sum = %d can be derived from the subset.",val);
      //toFindThe subset
      for(i=(row-1);;i--)
      {
          if(!table[i][val]) 
          {    printf("%d,", arrNum[i]);
                val = val - arrNum[i];
                
                if(val<=0)
                  break;
          }
      }    
   }
   else
   {
      printf("Sum = %d cannot be derived from the subset.",val);
   }
   }

