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
         //printf("I am here %d\n", temp);
         y->l = node;
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
   *lL = x;
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
//    printf("%d ",node->data);
    inorder(node->l);
    printf("%d", node->data);
    inorder(node->r);
  //  printf("%d ",node->data);
}
int max(int a , int b)
{
return (a>b?a:b);
}
int getheight(struct binTree *node)
{
   if(node == NULL)
     return 0;
   return (1+ max(getheight(node->r), getheight(node->l)));
}
int checkIfBalanced(struct binTree *node)
{
    if(node==NULL) 
        return 1;
    printf("Vi: %d", node->data);
    int r= getheight(node->r);
    int l= getheight(node->l);
    printf(" height of right= %d ",r);
    printf(" height of left = %d\n",l);
    if(r-l > 1 || r-l < -1)
        return 0;
    
    return (checkIfBalanced(node->r) && checkIfBalanced(node->l));
}
int search(struct binTree **node, int num, struct binTree **x,struct binTree **par)
{
struct binTree *temp = *node;
if (temp->data == num)
{//root is the node
*x = *node; 
return 1;
}
else{
for(;temp!=NULL;)
{ 
  if(temp->data< num)
   { 
  *par = temp;
  temp= temp->r;
   }
  else if(temp->data>num)
  {
  *par = temp;
  temp= temp->l;
  }  
else {
    *x = temp; 
    return 1;
  }
}
}
return 0;
}
int findMin(struct binTree **node,struct binTree **par)
{
struct binTree *temp = *node;
while(temp->l!=NULL)
{
*par = temp;
temp = temp->l;
}
*node = temp;
return temp->data;
}
void deleteNode(struct binTree **node, int num)
{
struct binTree *nodePtr;
struct binTree *parent=NULL;
struct binTree *nodeSucc;
int found = search(node,num,&nodePtr, &parent);
if(found)
{
printf("found the num= %d\n", nodePtr->data);
if(nodePtr->r!=NULL && nodePtr->l != NULL)
{
    //root node
    parent = nodePtr;
    nodeSucc = nodePtr->r;
    int a = findMin(&nodeSucc , &parent);
    nodePtr->data = a;
    nodePtr = nodeSucc;
}
if(nodePtr->r!=NULL && nodePtr->l == NULL)
{
       if(parent->r == nodePtr)
          parent->r = nodePtr->r;
       else
          parent->l = nodePtr->r;
       free(nodePtr);
}
else if(nodePtr->r==NULL && nodePtr->l != NULL)
{
       printf("I came here\n");
       if(parent->r == nodePtr)
          parent->r = nodePtr->l;
       else
          parent->l = nodePtr->l;
       
free(nodePtr);
}
else
{
 printf("I came herei 2\n");
       if(parent->r == nodePtr)
          parent->r = NULL;
       else
          parent->l = NULL;
       
free(nodePtr);
}
}
else {
printf("node was not found in the tree\n");
}

}

int height(struct binTree *node)
{
if(node==NULL) return 0;
else
  return (1+ max(height(node->r),height(node->l)));
}

checkForBalance(struct binTree *node)
{
   if(node == NULL)
      return 1;
   int h_r = height(node->r);
   int h_l = height(node->l);
   if(h_r-h_l>1 || h_r-h_l<-1)
    return 0;
   return(checkForBalance(node->r)&& checkForBalance(node->l));
}

void main()
{
insertBinTree(3,&abc);
insertBinTree(1,&abc);
insertBinTree(2,&abc);
insertBinTree(4, &abc);
insertBinTree(5,&abc);
inorder(abc);

if(checkIfBalanced(abc))
   printf("Tree is balanced");
else
   printf("Tree is not balance");

if(checkForBalance(abc))
   printf("Tree is balanced");
else
   printf("Tree is not balance");



printf("Depth first search");
//abc->l->r->l = abc;
//abc->l->r->l = abc;
//abc->r->r->r =abc;
DFS(abc);

if(noVisited(5))
{
printf("\nThere is no path between 5 and 1");
}
else
{
printf("There is a path between two nodes\n");
}

deleteNode(&abc,5);

deleteNode(&abc,3);

inorder(abc);
  
}

