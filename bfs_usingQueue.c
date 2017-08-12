#include<stdio.h>
struct binTree *abc =NULL;
struct stack *stk =NULL;
struct stack *head = NULL;
struct stack *tail = NULL;
struct linkedList *lL = NULL;
struct linkedList * x[10];

struct binTree {
   struct binTree * r;
   struct binTree * l;
   int data;
};

struct stack {
   struct binTree * node;
   struct stack *link;
};

void enqueue(struct stack **head, struct stack **tail, struct binTree *a)
{ 
   if(a==NULL)
   {
     return;
   }
   struct stack * node_q;
    node_q = (struct stack *)(malloc (sizeof(struct stack)));
    node_q->node = a;
    node_q->link = NULL;
    if(*head==NULL)
    {
      *head = node_q;
      *tail = node_q;
    }
    else
    {
    (*tail) ->link = node_q;
    }
}

struct binTree * dequeue()
{
   if(head == NULL)
      return NULL;
   else
    {
    struct stack * node;
    node = head;
    struct binTree *x  = node->node;
    head = head->link;
    if(head== NULL)
     tail = NULL;
    free(node);
    return x;
   }
     
}
int isEmpty()
{
if(head==NULL)
  return 1;
else
  return 0;
} 

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
}
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

void BFS(struct binTree *a)
{
struct binTree *node;
int data;

if(a== NULL)
  return;

   if(noVisited(a->data))
   {   
     append(&lL, a->data);
     if(!isEmpty(head))
     {
        //append(&lL, a->data);
        node = dequeue();
        printf("\n Visiting %d", node->data);
        BFS(node->r);
        BFS(node->l);         
     }
     else
     {  
        printf("Enqueuing %d", a->data); 
        enqueue(&head, &tail, a);
        BFS(a);
     }
  }
  //node =dequeue();
  //printf("\n Visiting %d", node->data);
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

void bfs(struct binTree *a)
{
struct binTree *node;
int data;
int h;
enqueue(&head,&tail,a);
do 
{
node = dequeue();
h = height(node);
append(&x[h],node->data);
printf("\n Visiting %d", node->data);
if(node==NULL)
  break;
if(noVisited(node->data))
{
append(&lL, node->data);
enqueue(&head,&tail,node->r);
enqueue(&head,&tail,node->l);
}
} while(node->r!=NULL || node->l!=NULL);

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
int i;
for(i=0;i<10;i++)
  x[i]  = NULL;
struct linkedList *temp;


insertBinTree(1,&abc);
insertBinTree(2,&abc);
insertBinTree(3,&abc);
insertBinTree(4, &abc);
insertBinTree(5,&abc);
inorder(abc);
//DFS(abc); 
printf("Breadth first search\n");
bfs(abc);

for(i=0;i<10;i++)
{
   temp = x[i];
   printf("level: %d",i);
   while(temp !=NULL)
   {
      printf("%d ",temp->data);
      temp= temp->link;
   }
}
}
