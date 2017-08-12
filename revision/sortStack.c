#include<stdio.h>
typedef struct node {
int val;
struct node * link;
} node;

node *stackPtr = NULL;

void push(int a)
{
node *temp = (node *)(malloc(sizeof(node)));
temp->val = a;
temp->link = stackPtr;
stackPtr = temp;
}

int pop()
{
if(stackPtr!=NULL)
{
int a = stackPtr->val;
node *temp = stackPtr;
stackPtr = stackPtr->link;
free(temp);
return a;
}
else 
return 0;
}
int top(node *root)
{
if(root != NULL)
return root->val;
else
return 0;
}
void sort(int temp,node *root)
{
if(temp < top(root) || root == NULL)
{
push(temp);
}
else
{
   int data = pop();
   sort(temp,root);
   push(data);
}
}
void sortStack(node * root)
{
if(root == NULL)
{
return;
}
else {
    int temp = pop();
    sortStack(stackPtr);
    sort(temp, stackPtr);
}
}
int main()
{
push(3);
push(2);
push(1);
push(4);
push(-1);
sortStack(stackPtr);
while(top(stackPtr)!=0)
{
printf("%d ",pop());
}
return 0;
}

