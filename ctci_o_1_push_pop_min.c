#include<stdio.h>
struct stack {
int data;
struct stack * link;
};
pushInternal(struct stack** s, int data)
{
struct stack* temp;
temp = (struct stack*)malloc(sizeof(struct stack));
temp->data = data;
temp->link = *s;
*s = temp;
}

int popInternal(struct stack **s)
{
  if(*s == NULL)
      return NULL;
  int temp;
  struct stack * x = *s;
  temp = (*s)->data;
  *s = (*s)->link;
  free(x);
  return temp;  
}
int min(struct stack *s)
{
   if(s == NULL)
   {
      return NULL;
   }
   else 
   {
      return s->data;
   }
}

void push(struct stack **Min, struct stack **normal, int data)
{
  if(data < min(*Min))
  {//push on both stacks.
     pushInternal(Min, data);
     pushInternal(normal, data);
  }
  else
  {
     pushInternal(normal, data);
  }
}
int pop(struct stack **Min, struct stack **normal)
{
   int temp;
   if(*normal == NULL)
   {
     return NULL;
   }
   temp = popInternal(normal);
   if(temp == min(*Min))
     popInternal(Min);
   return temp;
}
void main() {
 /*1. Create 2 stacks.
   2. One min stack and other normal stack.
   3. If we find an element > min element push it to the normal stack.
   4. If we find an elemnt < min element push it to both the stacks.
 */
struct stack *normalStack = NULL;
struct stack *minStack = NULL;
printf("\n Enter the number of elements.\n");
int noElements;
int element,i;
scanf("%d",&noElements);

for(i= 0 ; i<noElements; i++)
{
   scanf("%d",&element);
    push(&minStack,&normalStack, element);
}

printf("\n min = %d\n", min(minStack));

for(i= 0 ; i<noElements; i++)
{
   //scanf("%d",&element);
   printf("%d ", pop(&minStack,&normalStack));
}

}
