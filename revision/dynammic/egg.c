#include<stdio.h>
#define max(a,b) (((a)>(b))?(a):(b)) 
int main()
{
int numberOfFloors = 100;
int numberOfEggs = 2;
int matrix[2][101] ;
int i,j ;
for(j=0;j<=numberOfFloors;j++)
matrix[0][j] =j;

for(i=1;i<numberOfEggs;i++)
for(j=1;j<=numberOfFloors ; j++)
{
   if((i+1)>j)
      matrix[i][j] = matrix[i-1][j];
   else
   {
    int floors,min = 100000;
    for(floors=1;floors<=j;floors++)
    {
      
      if(min > max(matrix[i-1][floors-1], matrix[i][j-k]))
          min = max(matrix[i-1][floors-1], matrix[i][j-k]);
    }
    matrix[i][j] = 1+min;
   }
}

printf("%d",matrix[1][100] );

}
