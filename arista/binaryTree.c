#include<stdio.h>
#include<stdlib.h>
typedef struct btree {
int num;
struct btree *leftchild;
struct btree *rightchild;
} btree;
typedef struct linkedList {
  struct btree* node;
  struct linkedList* link;
} linkedList;
int isEmpty(struct linkedList * s);
struct btree* pop(linkedList ** s);
void push(linkedList ** stack, btree * n);
void postorder(struct btree * a);
void preorder(struct btree * a);
void inorder(struct btree * a);
void insert(struct btree ** a,int x);
void zigzagParsing(struct btree * a, struct linkedList ** s1, struct linkedList ** s2);

void main()
{
  struct btree *bt;
  struct linkedList *head1= NULL;
  struct linkedList *head2= NULL;
  struct linkedList **stack1 = &head1;
  struct linkedList **stack2 = &head2;
  int num;
  int i = 1;
  int temp;
  bt = NULL;
  printf("Enter Number of elements in the binary tree:");
  scanf("%d", &num);
  for (i=1;i<=num;i++) {
     scanf("%d", &temp);
     insert(&bt,temp);
  }
  printf("\nInorder traversal of b tree\n");
  inorder(bt);
  printf("\nPre order traversal of b tree\n");  
  preorder(bt);
  printf("\nPostOrder traversal of b tree\n");
  postorder(bt);   
    zigzagParsing(bt, stack1, stack2);
  return;
}
/*
Algorithm:
1. Check to see if the stack1 and stack2 are empty.
2. If they are empty see if there are any more elements in the binary tree.
3. If there are entries in b tree add them to stack1 left to right order.
4. pop from stack1 . Each time we pop an element from stack1 add its child nodes left and right node to stack2 (based on the level we are in the tree. odd level ltor even level rtol)
 */
//int levelOfTree = 0;
void zigzagParsing(struct btree *bT, struct linkedList **stack1, struct linkedList **stack2)
{
  //int levelOfTree = 0;
  struct btree * temp = bT;
  struct btree *x;
  if (temp != NULL)
  {
    if(isEmpty(*stack1) && isEmpty(*stack2))
    {
      push(stack1,temp);
    }
  }
  printf("\n Zig Zag traversal:\n");
  while(1)
    {
      
      while(isEmpty(*stack1)!=1)
      {
        printf("\n");
        x = pop(stack1);
        printf("%d ",x->num);
        push(stack2, x->rightchild);
        push(stack2, x->leftchild);
      }

      while(isEmpty(*stack2)!=1)
      {
        x= pop(stack2);
        printf("\n");
        printf("%d ",x->num);
	push(stack1, x->leftchild);
        push(stack1, x->rightchild);
      }
      if(isEmpty(*stack1) && isEmpty(*stack2))     
          break;
    }
  return;
}
int isEmpty(struct linkedList * s)
{
  if(s==NULL)
    return 1;
  else 
    return 0; 
}

void push(linkedList **s, btree *node)
{
  if (node ==NULL)
    return;
  struct linkedList *temp;
  temp = (struct linkedList *)(malloc(sizeof(struct linkedList)));
  temp->node = node;
  temp->link = *s;
  *s = temp;  
}
struct btree* pop(struct linkedList **s)
{ 
  if(isEmpty(*s))
   return NULL;
  struct linkedList *temp = *s;
  *s = temp->link;
  struct btree * tempNode = temp->node;
  free(temp); 
  return tempNode;
}

void insert(struct btree **a,int x)
{
  if (*a == NULL) 
  {
    *a = malloc(sizeof(struct btree));
    (*a)->leftchild = NULL;
    (*a)->rightchild = NULL;
    (*a)->num =x; 
    return;
  } 
  else 
  {
    if ((*a)->num > x) 
    {
       insert(&((*a)->leftchild),x);
    } 
    else 
    {
       insert(&((*a)->rightchild),x);
    }
  }
  return;
}

void inorder(struct btree *a)
{
  if(a!=NULL)
  {
    inorder(a->leftchild);
    printf("%d ",a->num);
    inorder(a->rightchild);
  }
  else 
    return;
}


void preorder(struct btree *a)
{
  if(a!=NULL)
  {
    printf(" %d ",a->num);
    preorder(a->leftchild);
    preorder(a->rightchild);
  } else {
    return; 
  }
}

void postorder(struct btree *a)
{
 
if(a!=NULL)
  {
    postorder(a->leftchild);
    postorder(a->rightchild);
    printf("%d ",a->num);
  } else {
    return;
  } 
}

