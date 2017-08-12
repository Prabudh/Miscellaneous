#include<stdio.h>
int ** my2DAlloc(int rows, int cols);
int main()
{
int rows = 3;
int cols = 4;

int **rowPtr = my2DAlloc(rows,cols);

int i,j;
for(i=0;i<rows;i++)
{
for(j=0;j<cols;j++)
rowPtr[i][j] = i+j;
}

for(i=0;i<rows;i++)
{
for(j=0;j<cols;j++)
    printf("%d ",rowPtr[i][j]);

printf("\n");
}

free(rowPtr);

 
}

int ** my2DAlloc(int rows, int cols)  {
    int i;
    int header = rows *sizeof(int*);
    int data = rows*cols*sizeof(int);
int ** rowptr = (int**)malloc(header+data);
if(rowptr == NULL) return NULL;
int * buf = (int*) (rowptr+rows);
for(i=0;i<rows;i++) {
rowptr[i] = buf +i*cols;
}
return rowptr;
}
