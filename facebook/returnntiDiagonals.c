#include<stdio.h>
#include<stdlib.h>

/**
 * @input A : 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row, and first entry in result array must be size of that row.  
 */
int ** diagonal(int** A, int n11, int n12, int *len1) {
    int i,j;
    int **result=(int **)(malloc(sizeof(int*)*(2*n11-1)));
    
    *len1 = 2*n11-1;
    int *tempResArray = (int *)(malloc(sizeof(int)*(*len1)));
    int count=0 ;
    for(i=1;i<=n11;i++)
    {
        for(j=1;j<=i;j++)
        {
          printf("%d,",A[i-j][j-1]);
          tempResArray[count] = A[i-j][j-1];
          count++;
        }
        printf("\n");
    }
   
    for(i=1;i<n11;i++)
    {
    for(j=i;j<n12;j++)
    {
    printf("%d,",A[n11+i-j-1][j]);
    tempResArray[count] = A[n11+i-j-1][j];
    count++;
    }
    }

    printf("\ncount = %d",count);
    count =0;
    printf("\n");
    for(i=0;i<=(*len1)/2;i++)
    {
        //printf("i=%d,",i);
        result[i]= (int*)malloc(sizeof(int)*(i+1));
        for(j=0;j<=i;j++)
        {
        printf("%d,%d,%d",i,j,);
        result[i][j]=tempResArray[count];
        count++;
        }
    }
    j=i;
    i--;i--;
    for(;i>=0;i--)
    {
        //printf("\ni=%d,",(i));
        result[j] = (int*)malloc(sizeof(int)*(i+1));
        for(int k=0;k<=i;k++)
        {
        result[j][k]=tempResArray[count];
        count++;
        printf("\ncount = %d",count);
        }
    j++;    
    }
    printf("\n");
    return result;
}

int main()
{
int **test=(int**)malloc(sizeof(int*)*3);
int count =0;
for(int x=0;x<3;x++)
{
test[x] = (int *)malloc(sizeof(int)*3);
test[x][0] =x+1+2*count;
test[x][1] =x+2+2*count;
test[x][2] = x+3+2*count;
count++;
}      
int len;
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
printf("%d",test[i][j]);
printf("\n");
}

int **array = diagonal(test,3,3,&len);
printf("\n");
    int i,j; 
    for(i=0;i<=len/2;i++)
    {
        //printf("%d,",i);
        for(j=0;j<=i;j++)
        {
          printf("%d,",array[i][j]);
        }
    }

    int temp = i;
    j=i;
    i--;i--;
    for(;i>=0;i--)
    {
        for(temp=0;temp<=i;temp++)
        {
            printf("%d,",array[j][temp]);
        } 
       j++;
    }

return 0;
}
