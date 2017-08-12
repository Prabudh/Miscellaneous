#include<stdio.h>
struct stack {
int data;
struct stack* link;
};
void push(struct stack**s, int data)
{
struct stack *temp = (struct stack *)(malloc (sizeof(struct stack)));
temp->data = data;
temp->link = *s;
*s = temp;
}
int pop(struct stack** s)
{
if(*s == NULL)
return NULL;

int temp = (*s)->data;
struct stack * node = *s;
*s = node->link;
free(node);
return temp;
}
int isEmpty(struct stack *s)
{
if(s == NULL)
return 1;
else
return 0;
}

struct stack *s1 = NULL;
struct stack *s2 = NULL;
//optimized push.
void enqueue(int data)
{
int emptyS1 = isEmpty(s1);
int emptyS2 = isEmpty(s2);
push(&s1,data);
}


int dequeue()
{
int data;
int emptyS1 = isEmpty(s1);
int emptyS2 = isEmpty(s2);

if(!emptyS2)
{
return pop(&s2);
}
while(s1!=NULL)
{
data = pop(&s1);
push(&s2,data);
}
return pop(&s2);
}
void main()
{
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  printf("%d ", dequeue());
  printf("%d ", dequeue());
  enqueue(50) ;
  enqueue(-10);
  enqueue(-11);
  printf("%d ", dequeue());
  printf("%d ", dequeue());
  printf("%d ", dequeue());
  printf("%d ", dequeue());
  printf("%d ", dequeue());
  printf("%d ", dequeue());
  printf("%d ", dequeue());
  printf("%d ", dequeue());
}
