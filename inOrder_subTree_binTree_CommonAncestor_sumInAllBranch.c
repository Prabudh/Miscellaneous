#include<stdio.h>
struct binTree {
struct binTree *r;
int data;
struct binTree *l;
struct binTree *up;
};
struct node {
struct node *link;
int data;
};
struct node *linkedList = NULL;

void insertLl(struct node **n, int data)
{
struct node * x = (struct node*)(malloc(sizeof(struct node)));
x->data = data;
x->link = NULL;
struct node *temp = *n;
if(temp == NULL)
{
   *n = x;
   return;
}
while(temp->link != NULL)
{
temp=temp->link;
}
temp->link = x;
}

int deleteLl(struct node **n)
{
if(*n == NULL)
return 0;

int a;
struct node *temp = *n;
*n = temp->link;
a = temp->data;
free(temp);
return a;
}

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

void insertBinTree(struct binTree ** root, int data)
{
struct binTree *temp = *root;
struct binTree *node;
node = (struct binTree*)malloc(sizeof(struct binTree));
node->r = NULL;
node->l = NULL;
node->up = NULL;
node->data = data;

if(*root == NULL)
{
*root = node;
return;
}
struct binTree *old;

while(temp!=NULL)
{
old = temp;
if(data > temp->data)
   temp= temp->r;
else
   temp=temp->l;
}
if(old->data <data)
{
old->r = node;
node->up = old;
return;
}
else{
old->l = node;
node->up = old;
return;
}

}

void searchAndToArray(struct binTree *tree, struct binTree **par,int *found, struct binTree **node,int data, int *array)
{
*par = NULL;
*found = 0;
*node = tree;
int i = 0;
  while(tree != NULL)
  {
   printf("%d ", tree->data);
   array[i] = tree->data;
   i++;
   if(tree->data == data)
   {
      *found = 1;
      *node = tree;
      return;
   }
   *par = tree;
   if(tree->data > data)
      tree = tree->l;
   else
      tree = tree->r;
  }
  return;
}

void search(struct binTree *tree, struct binTree **par,int *found, struct binTree **node,int data)
{
*par = NULL;
*found = 0;
*node = tree;
  while(tree != NULL)
  {
   if(tree->data == data)
   {
      *found = 1;
      *node = tree;
      return;
   }
   *par = tree;
   if(tree->data > data)
      tree = tree->l;
   else
      tree = tree->r;
  }
  return; 
}
int findSucc(struct binTree *x, int data)
{
 int found = 0;
 struct binTree *parent;
 struct binTree *node;
 
 search(x,&parent, &found, &node, data);
 if(found==1)
 {
   if(parent != NULL && node->data < parent->data)
   {
      return parent->data;
   }
   else 
   {
    while(node->up != NULL)
    {
       node = node->up;
       if(data<node->data)
         return data;
    }
    if(node->r!=NULL)
      return node->r->data;
   }
 }
 else 
 {
    printf("Not able to find the node.\n");
 } 
return 0;
}

int commonAncestor(struct binTree *root, int a, int b)
{
   int array1[100]={0};
   int array2[100]={0};
   int old;
   int found = 0;
   struct binTree *parent;
   struct binTree *node;
   
   printf("\n Ancestors for the node\n");
   searchAndToArray(root,&parent, &found, &node, a, array1);
   printf("\n"); 
   searchAndToArray(root,&parent, &found, &node, b, array2);
   int i=0;
   for (i=0;i<100;)
   {
      if(array1[i] == array2[i])
      {
        old = array1[i];
        i++;
      } 
      else
        break;
   }
   return old;
}
int visited[100] = {0};
int array[100];
void insert(int range_l, int range_h, struct binTree **bT)
{
   if(range_h == range_l)
      return;
   printf("range_l = %d, range_h = %d\n", range_l, range_h);
   int mid = (range_l+range_h) /2;

   //printf(" mid = %d\n ", mid);
   if(visited[array[mid]] == 0)
   {
     printf(" mid = %d\n ", mid);
     insertBinTree(bT,array[mid]);
     //insert_binTree(array[mid], &bT);
     visited[array[mid]] = 1;
   }
   else
   {

   }
   if(mid == range_l || mid == range_h)
     return;
   insert(range_l,mid,bT);
   insert(mid,range_h,bT);
}
void levelOrder(struct binTree *a)
{
   if(a == NULL)
      return;
   levelOrder(a->l);
   printf("%d ", a->data);
   levelOrder(a->r);
}
//int enterSubTree = 0;
int isSubtree = 1;
int preorder(struct binTree *a,struct binTree *b, int enterSubTree)
{
//int enterSubTree = 0;
   //int isSubtree = 1;
   if(a == NULL)
      return isSubtree;
   if(b==NULL)
   {
     printf("Yes it is a subtree\n");
     return isSubtree;
   }
   //printf("%d ", a->data);
   if(a->data == b->data)
   {
      printf("%d ", a->data);
      enterSubTree = 1;
      preorder(a->l,b->l, enterSubTree);
      preorder(a->r,b->r, enterSubTree);
      return isSubtree;
   }
   else if (enterSubTree == 1 && a->data != b->data)
   {
       printf("\nDid not match a= %d, b= %d\n", a->data, b->data);
       isSubtree = 0;
       return isSubtree;
   }
   else {
       preorder(a->l, b, enterSubTree);
       preorder(a->r, b, enterSubTree);
   }
return isSubtree;
}
int checkIfSubTree(struct binTree *tree, struct binTree *subTree)
{
 if (preorder(tree, subTree, 0)==1)
 {
    printf("Yes it is a subtree\n");
    return 1;
 } 
else
{ 
    printf("\nNo");
    return 0;
}
}
void displayLl(struct node *x)
{
   while(x!=NULL)
   {
      printf("%d ",x->data);
      x=x->link;
    }
}
void preOrderCheckSum(struct binTree *tree, int root,int s)
{
   int a;

   if(tree ==NULL)
       return;
   if(root+tree->data > s)
   {
       a = deleteLl(&linkedList);
       root= root-a;
   }
   else if(root+tree->data == s)
   {
       displayLl(linkedList);
       while(linkedList == NULL)
       {
           deleteLl(&linkedList);  
       }
   }
   //printf("%d", tree->data);
   preOrderCheckSum(tree->l, root+tree->data, s);
   preOrderCheckSum(tree->r, root+tree->data, s);
}
void findAllTheBranch(struct binTree *tree, int sum)
{
   int array1[100] ={0};
   if(sum > tree->data)
      insertLl(&linkedList, tree->data);
   preOrderCheckSum(tree->r,sum, tree->data);
   preOrderCheckSum(tree->l, sum, tree->data);
}
void main()
{
 struct binTree *new = NULL;
 struct binTree *subTree = NULL;
 int i =0;
 for (i=0;i<100;i++)
   array[i] = i; 
  //insertBinTree(&new, 1);
   insert(0,99,&new);
 for (i=0;i<100;i++)
   visited[i] = 0;

   insert(1,6, &subTree);   
   levelOrder(new);   
   levelOrder(subTree);
  printf("\nfind Successor 1: %d\n",findSucc(new ,1));
  
  printf("\nfind Successor 3 : %d\n",findSucc(new ,3));
  
  printf("\n find Successor 4: %d\n", findSucc(new,4));

  printf("Common ancestor of 44 and 99 =%d\n", commonAncestor(new, 44, 99));
  printf("Common ancestor of 2 and 99 =%d\n", commonAncestor(new, 2, 99));

  if(checkIfSubTree(new,subTree) == 1)
     printf("Yes it is a subTree");
  int sum = 4;
  findAllTheBranch(new,sum);

}


