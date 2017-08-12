#include<stdio.h>
//linked list reversal
typedef struct node {
   struct node* next;
   int data;
   struct node* l_next;
} node;
void insertLinked(node** root,int data)
{
node *temp=(node *)malloc(sizeof(node));
temp->data = data;
temp->next= NULL;
temp->l_next = NULL;
if(*root==NULL)
{
*root= temp;
return;
}
node *x = *root;

while(x->next!=NULL)
{
x=x->next;
}
temp->l_next = x;
x->next = temp;
}

void display(node *root)
{
node *temp = root;
while(temp!=NULL)
{
printf("%d, ",temp->data);
temp= temp->next;
}
}

void reverse(node** root)
{
node* r = NULL;
node* s =NULL;
node* q = *root;

while(q!=NULL)
{
    s= q;
    q= q->next;
    s->next = r;
    s->l_next = q;
    r= s;
}
*root = s;

}
int main()
{
   node *root = NULL;
   insertLinked(&root,1);
   insertLinked(&root,2);
   insertLinked(&root,3);
   insertLinked(&root,4);
   insertLinked(&root,5);
   insertLinked(&root,6);
   display(root);
   reverse(&root);
   display(root);
}
