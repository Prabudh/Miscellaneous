#include <stdio.h>
int array[] = {1,2,4,6,3,7,8};

struct node {
int data;
struct node *l;
struct node *r;
};
struct node *root = NULL;
void insertBinTree(struct node **r,int data)
{
    struct node *temp = (struct node*)(malloc(sizeof(struct node)));
    temp->r =NULL;
    temp->l = NULL;
    temp->data = data;

    if(*r == NULL)
    {
        *r = temp;
        return;
    }
    struct node *new= *r;
    struct node *old;
    
    while(new!=NULL)
    {
         old = new;
         if(new->data < data)
            new = new->r;
         else
            new =new->l;
      
    }
    if(old->data < data)
            old->r = temp;
         else
            old->l = temp;
return;  
}
int i = 0;

void inorder(struct node *x)
{
if(x==NULL)
return;
inorder(x->l);
printf(" %d ",x->data);
array[i] = x->data;
i++;
inorder(x->r);
}
void main() {
   for(i=0;i<7;i++)
      printf("%d",array[i]);

   for (i=0;i<7;i++)
    insertBinTree(&root,array[i]);
   i=0;
   inorder(root); 
   for(i=0;i<7;i++)
   {
     if(i>0 && (array[i]-array[i-1] >1))
     {
      printf("%d",array[i]-1);
     }
   } 
}

