/*
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
*/
#include<stdio.h>
#define N 10

int findThePositionOfQueen(int mat[N][N],int level);
int main()
{
	int mat[N][N] = {0};
	int val = 0;
        int bool=0;
	for(int i= 0; i<N;)
        {
        for(int j = 0 ;j<N;j++)
          for(int k=0;k<N;k++)
          {   mat[j][k] =0;
          }
        if(i!=0)
           mat[0][i-1] = 0;

        mat[0][i] =1;
        if (bool=findThePositionOfQueen(mat,1))
           break;
        else
           i++;

        for(int j = 0 ; j<N;j++)
        {
                for(int k=0;k<N;k++)
                {
                        printf("%d ",mat[j][k]);
                }
                printf("\n");
        }
         printf("\n");
        }
        if(bool)
        {
           printf("was able to place the queens\n");
 
         }
         else
         { 
           printf("failed");
        }	
       for(int i = 0 ; i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
}

int findThePositionOfQueen(int mat[N][N],int level)
{
int place = 0;
int colPos =0;  
for(int col = 0 ; col<N; col++)
{  
   if(col!=0)
   {
     mat[level][col-1] = 0; //clearing the previous position
   }
   mat[level][col] = 1; //try to place the queen and check if te position is okay
   int topRight = col+level;
   int topLeft = level-col; 
   if(level>=1)
   { 
      for(int row=level-1;row>=0;row--)
      {
         for(int colPos = 0 ;colPos<N;colPos++)
         {
            if(mat[row][col] == 1)
            {
              mat[level][col] = 0;
              //printf("I came here as %d",mat[][]);
              place =0;
              break;
            }
            if(row-colPos == topLeft || row+colPos == topRight)
            {
              if(mat[row][colPos]==1)
              {
              mat[level][col] = 0;
              //printf("I came here as %d",mat[][]);
              place =0;
              break;
              }
            }
         place = 1;
         }
        if(place==0)
          break;
       }
    }
    else
    {
       place = 1;
    }
//print utility
printf("**********************i\n");
printf("place = %d\n",place);
    for(int i = 0 ; i<N;i++)
    {
        for(int j=0;j<N;j++)
            {
                   printf("%d ",mat[i][j]);
            }
           printf("\n");
    }
    printf("\n");

printf("**********************i\n");
    if (place && ((level+1) <N) && findThePositionOfQueen(mat,level+1))
       return 1;
    else if(level+1==N && place==1)
       return 1; 
 }

if(level != 0)
return 0;
else
return 1;
        
}

