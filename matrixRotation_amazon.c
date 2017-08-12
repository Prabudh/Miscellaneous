#include<stdio.h>
int matrix[4][4] = {{1,2,3,4},{4,5,6,7},{8,9,10,11},{12,13,14,15}};
void rotate(int mat[][4],int size)
{
int j,top,layer,i,first,last,offset;
for(layer=0;layer<size/2;layer++)
{
first = layer;
last = size-layer-1;
for(i=first;i<last ; i++)
{
offset = i-first;
top = matrix[first][i];
matrix[first][i] = matrix[last-offset][first];
matrix[last-offset][first] = matrix[last][last-offset];
matrix[last][last-offset] = matrix[i][last];
matrix[i][last] = top; 
}
}
for(i=0;i<4;i++)
{
for(j=0;j<4;j++)
{   printf("%d,",matrix[i][j]);
}
printf("\n");
}

}
main()
{
int i,j;
for(i=0;i<4;i++)
{
for(j=0;j<4;j++)
{   printf("%d,",matrix[i][j]);
}
printf("\n");
}

rotate(matrix, 4);


}
