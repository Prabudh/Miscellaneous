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
struct stack *s3 = NULL;
void moveDisk(char fp,char tp);

void moveTower(int height,char fromPole, char toPole, char withPole)
{  
  if (height >= 1)
  {
     moveTower(height-1,fromPole,withPole,toPole);
     moveDisk(fromPole,toPole);
     moveTower(height-1,withPole,toPole,fromPole);
  } 
}
void moveDisk(char fp,char tp)
{
    printf("moving disk from %c to %c\n",fp, tp);
}
void main()
{

moveTower(5,'A','B','C');

}
