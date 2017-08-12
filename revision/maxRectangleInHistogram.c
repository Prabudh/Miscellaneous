#include<stdio.h>
typedef struct node {
struct node * next;
int data;
}node;

void push(node **root,int dat)
{
node* temp = (node*)malloc(sizeof(node));
temp->data = dat;
temp->next = NULL;
if(*root==NULL)
*root = temp;
else
{
  temp->next = *root;
  *root = temp;
}
}

int pop(node **root)
{
if(*root!=NULL)
{
  int dat = (*root)->data;
  node* temp = *root;
  *root = (*root)->next;
  free(temp);
  return dat;
}
else
return -1;
}

int top(node *root)
{
if(root!=NULL)
{
  int dat = root->data;
  return dat;
}
else
return -1;
}

int isEmpty(node *root)
{
return (root==NULL?1:0);
}

findMaxArea(int hist[],int size)
{
int area =0, maxArea=0;
node* root = NULL;
int i;
for(i=0;i<size;)
{

if(isEmpty(root) || (top(root) < hist[i]))
{
    push(&root,i);
    i++;
}
else
{
/*
find area: 1.Ifempty
*/

int dat = pop(&root);
if(dat!=-1)
{
    if(isEmpty(root))
       area = hist[dat]*i;
    else
       area = hist[dat]*(i-top(root)-1);

    if(area>maxArea)
       maxArea = area;
}
}

}
while(!isEmpty(root))
{
int dat = pop(&root);
if(dat!=-1)
{
    if(isEmpty(root))
       area = hist[dat]*i;
    else
       area = hist[dat]*(i-top(root)-1);

    if(area>maxArea)
       maxArea = area;
}
}
printf("%d",maxArea);
}


int main()
{
int histogram[5] = {2,1,2,3,1};
findMaxArea(histogram,5);
}
