#include<stdio.h>
#define MAX 6
int array[MAX] = {0};
int front = -1;
int rear = -1;
void insertMinHeap(int data)
{
if(front==-1)
{
front++;
}
if((rear+1)<MAX)
   rear++;
else
{
printf("Min Heap full\n");
return;
}

array[rear] = data;
heapify_bottom();
}

heapify_bottom()
{
int rear_old;
for(int i = rear; i>=0;)
{
if(i==0)
break;
//printf("rear=%d ",rear);
if(array[i]<array[i/2])
{
 int temp = array[i];
 array[i] = array[i/2];
 array[i/2] = temp;
}
if(rear_old==i)
break;
rear_old = i;
if(i!=0)
  i= i-i/2;
else
{
  break;
}

}
}

int extractMin()
{
if(rear == -1)
return -1;
int temp = array[0];
array[0] = array[rear];
array[rear] = 0;
rear--;
if(rear==-1)
front=-1;
heapify_top();
return temp;
}
min(int a , int b)
{
if(array[a]==0)
return b;
if(array[b]==0)
return a;
return array[a]<array[b]? a:b;
}
heapify_top()
{
int a = 0;
for(int i = 0; i<=rear;)
{
a = min(2*i+1,2*i+2);

if(array[i]>array[a] && array[a]!=0)
{
 int temp = array[i];
 array[i] = array[a];
 array[a] = temp;
 i =a;
}
else
i++;
}
}

int display()
{
if(front==-1)
return 0;
for(int i = 0 ; i<=rear;i++)
{
printf("%d ",array[i]);
}
return 0;
}

int main()
{
insertMinHeap(2);
insertMinHeap(3);
insertMinHeap(5);
insertMinHeap(4);
insertMinHeap(50);
insertMinHeap(300);
insertMinHeap(40);
insertMinHeap(500);
insertMinHeap(30);
display();
printf("\n");
for(int i =0 ; i<MAX;i++)
printf("%d ",extractMin());

return 0;
}
