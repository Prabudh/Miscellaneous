#include<iostream>
using namespace std;
int histVal[10] = {1,2,3,4,4,4,4,1,1,5};
typedef struct node {
  struct node* next;
  int data;
} node;
node *sPtr = NULL;
void push(int dat)
{
  node* temp =(node*)malloc(sizeof(node));
  temp->data = dat;
  temp->next = sPtr;
  sPtr = temp;
}

int pop()
{
if(sPtr==NULL)
return -1;
else
  {
     node * t = sPtr;
     int temp = sPtr->data;
     sPtr= sPtr->next;
     free(t);
     return temp;
  }
}
int top()
{
if(sPtr!=NULL)
return sPtr->data;
else
return -1;
}
bool isEmpty()
{
if(top()==-1)
return 1;
else
return 0;
}

int main()
{
int i=0;
int area= 0;
int topIndex ;
int maxArea=0;
for(i=0;i<10;)
{
    if(isEmpty()|| histVal[top()]<histVal[i])
    {   
        push(i);
        printf("pushing %d, %d\n",i,histVal[i]);
        i++;
    }
    else
    {//pop and calculate the area.
       topIndex=pop() ;
       printf("popping %d and %d\n",topIndex,histVal[topIndex]);
       if(!isEmpty())
       { 
         area = histVal[topIndex]*(i-top()-1);
       }
       else
       {
         area = histVal[topIndex]*i;
       }
       if(area>maxArea)
          maxArea=area;
    }
}
while(!isEmpty())
{
topIndex = pop();
printf("popping %d and %d\n",topIndex,histVal[topIndex]);
if(!isEmpty())
area = histVal[topIndex]*(i-top()-1);
else
area = histVal[topIndex]*i;

if(area>maxArea)
    maxArea=area;
}
if(isEmpty())
{
    area = histVal[topIndex]*i;
}
printf("The Max area of histogram =%d",maxArea);
}
