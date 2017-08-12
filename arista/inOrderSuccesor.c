#include<stdio.h>
#define N 10
#define M 20
int main()
{
int *x[N];
x=(int *)malloc(M*sizeof(*x));
printf("%d %d",sizeof(x),sizeof(*x));
}
/*
with ParentPointer
node* inOrderSuccessor(node* x)
{
if(x->r!=NULL)
 return findMin(x->r);
else
 {
node *par = x->p;
while(par!=NULL && par->r == x)
{
x= par;
par = x->p;
}

}
return par;
}

without parentPointer
node* inOrderSuccessor(node *root,node* x)
{
if(x->r!=NULL)
 return findMin(x->r);
else
 {
    par = NULL;
    while(root != NULL)
    {
       if(x->data < root->data)
       {
          par = root;
          root = root->l;
       }
       else
       {
         root = root->r;
       }
       if(x->data == root->data)
          return par;
    }
 }
return par;
}
*/
