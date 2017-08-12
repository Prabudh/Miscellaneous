/*
2.1
 Write code to remove duplicates from an unsorted linked list FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct linkedList {
int data;
struct linkedList *next;
}linkedList;
checkTheMaxAndMinNumber(linkedList **h,int *min,int *max)
{
linkedList *temp =*h;
*min = 0;*max=0;
while(temp!=NULL)
{
if(*min > temp->data)
  *min = temp->data;
if(*max<temp->data)
  *max = temp->data;
temp=temp->next;
}
}
void toRemoveDuplicate(linkedList **head)
{
int max, min;
checkTheMaxAndMinNumber(head,&min,&max);
int diff = max-min;
int *array =(int *)malloc((diff+1)*sizeof(int));
for(int i=0;i<diff;i++)
array[i] =0;
addLibAndRemoveDup(array,*head,diff);
}
addLibAndRemoveDup(int array[],linkedList *l,int diff)
{
    linkedList *temp =l, *old_Temp;

    while(temp!=NULL)
    {
        if(array[temp->data+diff]==0)
        {
           array[temp->data+diff]++;
           old_Temp=temp;
        }
        else
        {
        //Remove Duplicate
          old_Temp->next = temp->next;
          free(temp);
        }
        temp= temp->next;
    }
}
insertLl(linkedList** x, int data)
{
linkedList *temp = (linkedList*)malloc(sizeof(linkedList));
temp->data = data;
temp->next = *x;
*x = temp;
}
displayList(linkedList *x)
{
while(x!=NULL)
{
printf("%d ",x->data);
x= x->next;
}
}
int main()
{
linkedList *aList= NULL;
insertLl(&aList, 1);
insertLl(&aList,2);
insertLl(&aList, 3);
insertLl(&aList, 3);
insertLl(&aList, 4);
displayList(aList);
toRemoveDuplicate(&aList);
displayList(aList);
}
