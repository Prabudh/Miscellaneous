#include<iostream>
using namespace std;
int main()
{
    int temp;
    printf("Enter nuber of eggs");
    int noOfEggs,nofloors; 
    scanf("%d",&noOfEggs);
    printf("Enter number of floors");
    scanf("%d", &nofloors);
    
    int **table,i,j,k;
    table = (int **)malloc(sizeof(int*)*noOfEggs);
    for(i=0;i<noOfEggs;i++ )
    {
        table[i] = (int*)malloc(sizeof(int)*(nofloors+1));
    } 

    for(i=0;i<=nofloors;i++)
    {
        table[0][i] = i;
    }
    for(i=0;i<noOfEggs;i++)
    {
        table[i][0] = 0;
    }
    
    for(i=1;i<noOfEggs;i++)
    { 
         for(j=1;j<=nofloors;j++)
         {
           if((i+1)<(j+1))
              table[i][j] = table[i-1][j];
           else
           {
              int min=INT_MAX;
              
              for(k=1;k<=j;k++)
              {
                 temp = max(table[i-1][k-1],table[i][j-k]);
                 if(min>temp)
                     min=temp;
              }
              table[i][j] = min+1;
            }
         } 
    }   
printf("%d",table[i-1][j-1]);         
        
}


/*(1,2) j = 1
max(0,table[1][0])
max(table[0][0],0)

(1,2,3) j = 2
max(0,table[1][1])
max(table[0][1],table[1][0])
max(table[0][1],0)

1,2,3,4 j=3
max(0,table[1][2])
max(table[0][1],table[1][1])
max(table[0][1],table[1][0])
max(table[0][2])
*/
