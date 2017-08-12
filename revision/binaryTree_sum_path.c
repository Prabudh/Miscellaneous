#include<stdio.h>
typedef struct bTreeNode {
struct bTreeNode *r;
struct bTreeNode *l;
int data;
} node;

void insert(int value, node** root)
{
node *temp = (node *)(malloc(sizeof(node)));
temp->data = value;
temp->r = NULL;
temp->l = NULL;
if(*root == NULL)
{
*root = temp;
return;
}
node *start = *root;
node *old;

while(start!=NULL)
{
old = start;
if(value>start->data)
start = start->r;
else
start = start->l;
}

if(old->data >value)
old->l = temp;
else
old->r= temp;
}
/*
void delete(int data, node **root)
{
node *n,*n_succ,*parent;
int found=0;
if(findParentNodePtr(*root, sum))
}
*/
int findPath(node * root, int sum, int tempSum)
{
if(root==NULL)
return 0;
tempSum = root->data + tempSum;
if(sum == tempSum)
{
printf(" %d",root->data);
return 1;
}
if(findPath(root->l,sum,tempSum))
{
printf(" %d",root->data);
}
if(findPath(root->r,sum,tempSum))
{
printf(" %d",root->data);
}

}
int main()
{
  int temp = 0;
  node *root = NULL;
  insert(10,&root);
  insert(12,&root);
  insert(5,&root);
  insert(7,&root);
  insert(4,&root);
  int bool; 
  if(findPath(root,22,temp))
  {
      printf("\n%d",root->data);
  }

}
