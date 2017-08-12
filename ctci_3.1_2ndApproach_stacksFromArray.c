#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_stack1 33
#define MAX_stack2 66
#define MAX_stack3 100
int stack1_index = 0;
int stack2_index = 33;
int stack3_index = 66;

struct stackNode {
int data;
int indexTopElement;
};

typedef struct list {
struct list *next;
int index;
}list;

list *freeIndex = NULL;

push_list(list **a, int num)
{
list *temp = (list *)malloc(sizeof(list));
temp->index = num;
temp->next = *a;
*a = temp;
}
void findAndDelete_list(list **a, int num) {
 list *temp =*a;
 list *temp_old = temp;
if(temp->index == num)
{
*a =temp->next;
free(temp);
return;
}

 while(temp!=NULL)
 {
    if(temp->index==num)
    {
      temp_old->next = temp->next;
      free(temp);
      return;
    }
    temp_old =temp;
    temp=temp->next;
 }   
}
int pop_list(list **a)
{
if(*a!=NULL)
{
int temp = (*a)->index;
list *x =*a;
*a = (*a)->next;
free(x);
return temp;
}
return -1;
}

int listOfFreeSlots(list **a)
{
int temp = -1;
if(a==NULL)
    printf("No more Empty slots\n");
else
 {
  temp = pop_list(a);
 }
return temp;
}
void push(struct stackNode *x, int data, int stackNum)
{
struct stackNode *a = (struct stackNode*)malloc(sizeof(struct stackNode)) ;
a->data = data;
a->indexTopElement = -1;
if(stackNum ==1)
{
if(stack1_index < MAX_stack1)
{
if(stack1_index != 0)
{
a->indexTopElement = stack1_index;
stack1_index = stack1_index++;
}
x[stack1_index] = *a;
}
else
{
int index = listOfFreeSlots(&freeIndex);
a->indexTopElement = stack1_index;
stack1_index = index;
if(index!=-1)
x[index] = *a;
}
}
else if(stackNum == 2)
{
if(stack2_index < MAX_stack2)
{
if(stack2_index != 0)
{
a->indexTopElement = stack2_index;
}
x[stack2_index++] = *a;
} 
else
{
int index = listOfFreeSlots(&freeIndex);
a->indexTopElement = stack2_index;
if(index!=-1)
x[index] = *a;
}
}
else
{
if(stack3_index < MAX_stack3)
{
if(stack3_index != 0)
{
a->indexTopElement = stack3_index;
}
x[stack3_index++] = *a;
} 
else
{
int index = listOfFreeSlots(&freeIndex);
a->indexTopElement = stack3_index;
if(index!=-1)
x[index] = *a;
}
}
}
int pop(struct stackNode *s, int stackNum)
{
if (s == NULL)
{
    printf("Empty stack\n");
    return -1;
}
else if(stackNum == 1)
{
if(stack1_index == 0)
return -1;
    struct stackNode temp = s[stack1_index];
    stack1_index = temp.indexTopElement;
    return temp.data;
}
else if(stackNum ==2)
{
if(stack2_index == 33)
return -1;
   struct stackNode temp = s[stack2_index];
    stack2_index = temp.indexTopElement;
    return temp.data;
}
else
{
if(stack3_index == 66)
return -1;

struct stackNode temp = s[stack3_index];
stack3_index = temp.indexTopElement;
return temp.data;
}
}

int main() {
struct stackNode array[100];
int *stack1 =&array[0],*stack2 =&array[33],*stack3= &array[66];
push(stack1, 10, 1);
push(stack2, 20, 2);
push(stack3, 30, 3);
 
//testcase(36,stack1,1);

//testcase(37,stack2,2);

//testcase(39,stack3,3);


printf("\n%d",pop(stack1,1));
printf("\n%d", pop(stack2,2));
printf("\n%d",pop(stack3,3));
return 0;
}

