/*Implement 3 stacks in a single array*/
#include<stdio.h>
int array[100] = {-1,-1};

push(int **s, int var,int stackNum)
{
if(*s==NULL)
{
if(array[1] == -1 && stackNum == 1)
   *s = &array[1];
else if(array[34] == -1 && stackNum == 2)
   *s = &array[34];
else if(array[67] == -1 && stackNum == 3)
   *s = &array[67];

if(*s==NULL)
{//none of the stack is available.
 return NULL;
}
**s = var;
}
else {
if(*s < &array[99] && stackNum == 3)
{
*s = *s+1;
s = var;
}
if(*s < &array[66] && stackNum == 2)
{
*s = *s+1;
s= var;
}
if(*s < &array[33] && stackNum == 1)
{//first stack
*s = *s+1;
s = var;
}
}
return NULL;
}

int pop(int **s)
{
int temp;
if(*s!=NULL)
{
  if(*s == &array[1] || *s == &array[34] || *s==&array[67])
  {  temp = **s;
     s = NULL;
  }
  else
  {
    temp = **s; 
    *s= *s-1;
  }
  return temp;
}
return NULL;
}

void main()
{
int i = 0;
while(i<100)
{
array[i] = -1;
i++;
}
int *stack1 = NULL;
int *stack2 = NULL;
int *stack3 = NULL;
push(&stack1, 2, 1);
//push(&stack1, 5, 1);
//push(&stack1, 7, 1);
push(&stack2, 3, 2);
//push(&stack2, 6, 2);
push(&stack3, 4, 3);
//push(&stack3, 7 ,3);
printf("\n%d",pop(&stack1));

printf("\n%d",pop(&stack2));

printf("\n%d",pop(&stack3));

printf("\n%d",pop(&stack1));

printf("\n%d",pop(&stack2));

printf("\n%d",pop(&stack3));
/*
printf("\n%d",pop(&stack1));

printf("\n%d",pop(&stack2));

printf("\n%d",pop(&stack3));
*/
}

