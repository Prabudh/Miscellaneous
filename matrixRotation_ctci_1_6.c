#include<stdio.h>
void rotateMatrix(int matrix[][5] , int n);
void main()
{
/*int arr[4][4] = { {1,2,3,10},
                  {4,5,6,11},
                  {7,8,9,12},
                  {13,14,15,16}
                };
*/
int arr[5][5] = { {1,2,3,10,-1},
                  {4,5,6,11,-2},
                  {7,8,9,12,-3},
                  {13,14,15,16,-4},
                  {-5,-6,-7,-8,-9}
                };
/*
result=
arr[4][4] = {
            {13,7,4,1},
            {14,8,5,2},
            {15,9,6,3},
            {16,12,11,10}
            }
*/

rotateMatrix(arr, 5);
int i,j;
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
   printf("%d ",arr[i][j]);
}
printf("\n");
}
setToZero(arr, 5);
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
   printf("%d ",arr[i][j]);
}
printf("\n");
}
}

void rotateMatrix(int matrix[][5] , int n)
{
	for(int layer =0; layer< n/2;++layer) {
          int first = layer;
          int last = n-1-layer;
          for(int i = first; i<last;++i) {
          int offset = i-first;
          int top = matrix[first][i];
          matrix[first][i] = matrix[last-offset][first];
          matrix[last-offset][first] = matrix[last][last-offset];
          matrix[last][last-offset] = matrix[i][last];
          matrix[i][last] = top;
  
          }
	}
}
struct linkedList {
int x;
int y;
struct linkedList *link;
};
void setToZero(int mat[][5], int n)
{
struct linkedList *cordts = NULL;
for(int i = 0; i<5; i++)
{
   for(int j = 0; j< 5; j++)
   {  
     if(mat[i][j] == 0)
      {
        appendList(&cordts, i, j);
      }
   }
}
i = -1;
j = -1;
int a,b;
while(1)
{
   i = -1;
   popLinkedList(&cordts, &i , &j);
   if(i == -1)
     break;
   else
   {
      for (a =0; a<5; a++)
        mat[a][j] =0;
      for(b= 0; b<5 ; b++)
        mat[i][b] =0;
    }
}
}

appendList(struct linkedList **head,int x,int y)
{
struct linkedList *temp;
temp = (struct linkedList *) (malloc(sizeof(struct linkedList)));
temp->x = x;
temp->y = y;
temp->link = *head;
*head = temp;
/*
if(*head == NULL)
{
*head = 
}
*/
}

popLinkedList(struct linkedList **head, int *x, int *y)
{
struct linkedList *temp = *head;
if(temp!= NULL)
{
*x = temp->x;
*y = temp->y;
*head = temp->link;
free(temp);
}

}
