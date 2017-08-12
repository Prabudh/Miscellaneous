#include<stdio.h>
typedef struct stackNode {
int data;
struct stackNode *next;
} stackNode;
struct stackNode* stack1= NULL;
struct stackNode* stack2= NULL;
void push(struct stackNode** x, int data)
{
struct stackNode* temp = (struct stackNode*)malloc(sizeof(struct stackNode));
temp->data = data;
temp->next = *x;
*x = temp;
}
int pop(stackNode** x)
{
if(x==NULL)
return -1;

int i = (*x)->data;
stackNode* temp = *x;
*x = temp->next;
free(temp);
return i;
}

int dequeue()
{
while(stack1!=NULL)
{
push(&stack2,pop(&stack1));
}
int i=-1;

if(stack2!=NULL)
i = pop(&stack2);

while(stack2!=NULL)
{
push(&stack1,pop(&stack2));
}
return i;
}
void enQueue(int data)
{
push(&stack1,data);
}
int main()
{
enQueue(10);
enQueue(11);
enQueue(100);

for(int i = 0; i<10;i++)
{
printf("%d,",dequeue());
}


return 0;
}
