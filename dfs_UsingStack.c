#include<stdio.h>
struct binTree {
   struct binTree * r;
   struct binTree * l;
   int data;
};

struct stack {
   struct binTree * node;
   struct stack *link;
};

struct binTree *root;

void insertBinTree(int temp, struct binTree **root) {
     struct binTree *node = (struct binTree *)malloc(sizeof(struct binTree));
     node->data = temp;
     node->r = NULL;
     node->l = NULL;
     
     if(*root ==NULL)
     {
         *root = node;
         return;
     }
     struct binTree *x = *root;
     struct binTree *y = *root;

     while(x !=NULL)
     {
       y = x;
       if(x->data < temp)
           x= x->r;
       else
           x= x->l; 
     }

     if(y->r == NULL && y->data <temp)
     {
          y->r = node;
          return;
     }
     if(y->l == NULL && y->data > temp)
     {
         y->l == node;
          return;
     }

}
struct binTree * peek(struct stack *s)
{
   if(s== NULL)
    return NULL;

   return s->node;
}
push(struct stack **s, struct binTree *node)
{
    struct stack *temp = *s;
    struct stack *x= (struct stack *)malloc(sizeof (struct stack));
    x->node = node;
    x->link = *s;
    *s = x;
}

struct binTree * pop(struct stack **s)
{
if(*s== NULL)
     return NULL;
else
 {
   struct binTree * temp;
   struct stack *x = *s;
   temp = (*s)->node;
   *s = (*s)->link;
   free(x);
   return temp;  
 }

}
struct linkedList
{
    int data;
    struct linkedList *link;
};

append(struct linkedList **lL, int temp)
{
   struct linkedList *x = (struct linkedList*) (malloc(sizeof(struct linkedList)));
   x->link = *lL;
   x->data = temp;
}
struct binTree *abc =NULL;
struct stack *stk =NULL;
struct linkedList *lL = NULL;
int noVisited(int x)
{
   struct linkedList *temp = lL;
   while(temp!=NULL)
   {
     if(temp->data == x)
       return 0;
     temp = temp->link;
   }
   return 1;
}
void DFS(struct binTree *a)
{
   if(a==NULL)
     return;
   if(noVisited(a->data))
   {
      push(&stk,a);
      append(&lL, a->data);
      DFS(a->r);
      DFS(a->l);
      printf("\nvisiting %d", a->data);
      pop(&stk);
   }
}

void inorder(struct binTree *node)
{
    if(node == NULL)
       return;
    inorder(node->l);
    inorder(node->r);
    printf("%d ",node->data);
}
void main()
{

insertBinTree(1,&abc);
insertBinTree(2,&abc);
insertBinTree(3,&abc);
insertBinTree(4, &abc);
insertBinTree(5,&abc);
inorder(abc);
DFS(abc); 

}
