#include<stdio.h>
struct binTree {
int data;
struct binTree *r;
struct binTree *l;
};
int max(int a, int b)
{
return ((a>b)? a:b);
}
struct binTree* newNode(int temp)
{
struct binTree *node = (struct binTree*) (malloc (sizeof(struct binTree)));
node->data = temp;
node->r = NULL;
node->l = NULL;
return node;
}
int height(struct binTree * x)
{
if(x== NULL)
return 0; 

return(1+max(height(x->left),height(x->right)));
}
void inOrder(struct binTree *x)
{
if (x == NULL)
 return;
inOrder(x->left);
printf("%d",x->data);
inOrder()x->right;;
}
void postOrder()
{
}

void main()
{
struct binTree *x = newNode(1);
x->l = newNode(2);
x->r = newnode(5);
x->l->l = newNode(6);
x->r->r = newNode(9); 
inOrder(x);
postOrder(x);
preOrder(x);
}



