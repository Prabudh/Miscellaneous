#include<stdio.h>
struct binTree {
struct binTree *r;
struct binTree *l;
int data;
};

struct binTree * bT = NULL;
int array[100] ;
/*
void main()
{
int i =0;
for (i=0;i<100;i++)
  array[i] = i;

//populate the binaryTree
int high = 99;
int low = 0;
insert(0,99);

}
*/
void insert_binTree(int x, struct binTree **tree)
{
  struct binTree * node = (struct binTree*)(malloc(sizeof(struct binTree)));
  node->data = x;
  node->l = NULL;
  node->r = NULL;
  
  if(*tree == NULL)
  {
     *tree = node;
     return;
  }  

  struct binTree *temp = *tree;
  struct binTree *y;
  while(temp!=NULL)
  {
     y = temp;
     if(temp->data < x)
     {
        temp = temp->r;
     } 
     else
        temp= temp->l;
  }
  if(y->r == NULL && y->data < x)
  {
     y->r =node;
  }
  else if(y->l == NULL && y->data > x)
  { 
     y->l = node; 
  }  
}
int visited[100] = {0};

void insert(int range_l, int range_h)
{
   if(range_h == range_l)
      return;
   //printf("range_l = %d, range_h = %d\n", range_l, range_h);
   int mid = (range_l+range_h) /2;
   
   printf(" mid = %d\n ", mid);
   if(visited[array[mid]] == 0)
   { 
     insert_binTree(array[mid], &bT);
     visited[array[mid]] = 1;
   }
   else 
   {
     
   }
   if(mid == range_l || mid == range_h)
     return;
   insert(range_l,mid);
   insert(mid,range_h);
}

int max(int a,int b)
{
return (a>b?a:b);
}

int height(struct binTree *a)
{
  if(a == NULL)
    return 0;
  else
     return (1+ max(height(a->l),height(a->r)));
} 

void levelOrder(struct binTree *a)
{
   if(a == NULL)
      return;
   levelOrder(a->l);
   printf("%d ", a->data);
   levelOrder(a->r);
}
void search(struct binTree *bt, struct binTree **parent , struct binTree **x, int *found, int data);
void delete(struct binTree **bTree, int data)
{
struct binTree* parent = NULL, *x = NULL, *xsucc = NULL;
int found =0;
search(*bTree, &parent,&x, &found, data);

//if both children of x ==NULL
if(found ==0)
{
  printf("No such child in the binary tree");
  return;
}
if(x->r!=NULL && x->l!=NULL)
{
   xsucc = x->r;
   parent = x;
   while(xsucc->l !=NULL)
   {
      parent = xsucc;
      xsucc = xsucc->l;
   }
   x->data = xsucc->data;
   x = xsucc;
}  

if(x->l==NULL && x->r==NULL)
{
   if(parent->r == x)
     parent->r = NULL;
   else if(parent->l == x)
     parent->l = NULL;
   free(x);
   return;
}
if(x->l !=NULL && x->r ==NULL)
{
   if(parent->r == x)
      parent->r = x->l;
   else
      parent->l = x->l;
  free (x);
  return;
}
if(x->r !=NULL && x->l == NULL)
{
   if(parent->r == x)
      parent->r = x->r;
   else
      parent->l = x->r;
  free (x);
  return;
}
}

void search(struct binTree *bt, struct binTree **parent , struct binTree **x, int *found, int data)
{
*found = 0;
*parent = NULL;
*x= bt;
while(bt!=NULL)
{
   if(data == bt->data)
   {
    *x = bt;
    *found = 1;
    return;
   }   
   parent = bt;
   if(data > bt->data)
     bt=bt->r;
   else
     bt = bt->l;
   
}
}
void main()
{
int i =0;
for (i=0;i<100;i++)
  array[i] = i;

//populate the binaryTree
int high = 99;
int low = 0;
insert(0,99);
levelOrder(bT);
printf("height = %d\n", height(bT));

delete(&bT,10);
delete(&bT,90);
levelOrder(bT);

}

/*
if(x->r != NULL && x->l !=NULL)
{
xsucc = x->r;
parent =x;
while(xsucc->l != NULL)
{
  parent = xsucc;
  xsucc =xsucc->l;
}
x->data = xsucc->data;
x= xsucc;
} 
if(x->r!=NULL && x->l ==NULL)
{
  if(parent->r == x)
     parent->r = x->r;
  else
    parent->l = x->r;
  free (x);
}
if(x->l!=NULL && x->r == NULL)
{

}
if(x->l== NULL && x->r == NULL)
{
if(parent->r == x)
   parent->r = NULL;
else
   parent->l = NULL;
free(x);
}
