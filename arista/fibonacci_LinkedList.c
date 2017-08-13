#include<stdio.h>
#include<stdlib.h>
typedef struct node {
  int data;
  struct node *link;
} node;

void addToList(node **x, int dat)
{
  node *temp = (node *)malloc(sizeof(node));
  temp->data = dat;
  temp->link = NULL;
  if(*x == NULL)
  {
     *x = temp;
     return; 
  }
  node *y = *x;
  while(y->link!=NULL)
     y= y->link;
  y->link = temp;
  return;
}
void displayList(node *x)
{
   while(x!=NULL)
   {
      printf("%d ",x->data);
      x= x->link; 
   }
}
int current = 0;
int previousNum;
int nextsum;

void displayFibonacciList(node *x)
{
   int sum = 1;
   previousNum = sum;
   while(x!=NULL)
   {
      current++; 
      if(current == sum)
      {
         printf("%d ",x->data);
         sum = sum + previousNum;
         previousNum = current;
      }
       x= x->link;
   }
}

int main(){
  node *list = NULL;
  addToList(&list, 1);
  
  addToList(&list, 2);
  
  addToList(&list, 3);
  
  addToList(&list, 4);
  
  addToList(&list, 5);
  
  addToList(&list, 6);

  addToList(&list, 7);

  addToList(&list, 8);

  addToList(&list, 9);

  addToList(&list, 10);

  addToList(&list, 11);

  addToList(&list, 12); 
 
  displayList(list);

printf("\n");  
  displayFibonacciList(list);
printf("\n");
}
