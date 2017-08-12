#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct lL {
int data;
struct lL * next;
} ;
void insert(struct lL **l , int n)
{
    struct lL *node = (struct lL *)malloc(sizeof(struct lL));
    node->data = n;
    node->next = NULL;
    if(*l == NULL)
    {
       *l = node;
       return;
    }
    else
    {
       struct lL *temp = *l;
       while(temp->next != NULL)
       {
           temp = temp->next;
       } 
       temp->next = node;
    }
  return;
}
void reverse(struct lL **q)
{
struct lL *r,*s,*temp =*q;
r= NULL;
while(temp!=NULL)
{
s= temp;

temp = temp->next;
s->next = r;
r =s;
}
*q =s;
}
void removeDuplicate(struct lL *l)
{
struct lL *slow, *fast,*old= l,*temp;
slow = l;fast =l->next;
for(;slow!=NULL;)
{
   fast = slow->next;
   old = slow;
   for(;fast!= NULL;)
   {
      printf("slow = %d, fast =%d", slow->data, fast->data);
       if(slow->data != fast->data)
       {
           old = fast;
           fast = fast->next;
       }
       else
       {
           temp = fast;
           old->next = fast->next;
           fast = fast->next;
           free(temp);
       }
   }
   printf("fast is NULL\n"); 
   slow = slow->next;
}
}
void printlL(struct lL * l)
{
while(l!=NULL)
{
printf("%d, ",l->data);
l= l->next;
}
}
int main()
{
struct lL *root = NULL;
int numOfElem = 0;
scanf("%d",&numOfElem);
int num;
for (int i= 0; i< numOfElem ;i++)
{
scanf("%d",&num);
insert(&root, num);
}
removeDuplicate(root);
printlL(root);
reverse(&root);
printf("\n");
printlL(root);
return 0;
}
