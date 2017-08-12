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

int topOfStack(struct stack *s)
{
if(s==NULL)
{
return NULL;
}
else{
return s->data;
}
}
void main()
{
push(&s1, 1);
push(&s1, -2);
push(&s1, 500);
push(&s1, -1000);
sortStack(&s1);
printf("%d ",pop(&s1));
printf("%d ",pop(&s1));
printf("%d ",pop(&s1));
printf("%d ",pop(&s1));
}
sortList(struct stack **s,int data)
{
    int temp;
    if(*s==NULL || data > topOfStack(*s))
       push(s,data);
    else
    {
       temp = pop(s);
       sortList(s,data);
       push(s,temp);
    }
}
sortStack(struct stack **s)
{
   int temp;
   if(*s!=NULL)
   {
      temp=pop(s);
      sortStack(s);
      sortList(s,temp);
   }
}

