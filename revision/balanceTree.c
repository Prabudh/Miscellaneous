#include<stdio.h>

typedef struct bTreeNode {
    struct bTreeNode *l;
    struct bTreeNode *r;
    int val;
} bTreeNode;
bTreeNode * findmin(bTreeNode *root, bTreeNode **par)
{
bTreeNode * temp = root;
if(root == NULL)
return NULL;
while(temp->l!= NULL)
{
    *par = temp;
    temp = temp->l;
}
return temp;
}
void insertBTree(bTreeNode **root, int val)
{
bTreeNode *temp = (bTreeNode*)(malloc(sizeof(bTreeNode)));
temp->val = val;
temp->r = NULL;
temp->l = NULL;
bTreeNode *x, *y;
x= *root;
if(x== NULL)
{
*root = temp;
return;
}
while(x!=NULL)
{
y = x;
if(val>x->val)
{
x= x->r;
}
else
x= x->l;
}

if(y->val < val)
y->r = temp;
else
y->l =temp;

}
int search(bTreeNode *node ,int data, bTreeNode **x, bTreeNode **par)
{
bTreeNode *temp = node;
while(temp!= NULL)
{
  if(data == temp->val)
  {
       *x = temp;
       return 1;
  }
  *par = temp;
  if(data > temp->val)
     temp = temp->r;
  else 
     temp= temp->l;
}

return 0;
}
void inorder(bTreeNode *root)
{
if(root == NULL)
return;
inorder(root->l);
printf("%d, ",root->val);
inorder(root->r);
}
void delete(bTreeNode **root, int data)
{
if(*root== NULL)
{
printf("treeEmpty");
return;
}
bTreeNode *x, *par, *xsucc;
if(search(root, data, &x, &par))
{
    if(x->r != NULL && x->l != NULL)
    {
       par = x;
       xsucc = findmin(x->r, &par);
       /*if(xsucc == NULL)
       {
          xsucc = x->r;
          par = x;
       }*/
       x->val = xsucc->val;
       x= xsucc;
     }
    if(x->r==NULL && x->l == NULL)
    {
       if(par->r == x)
         par->r = NULL;
       else
         par->l = NULL;

       free(x);
    }
    else if(x->r!= NULL && x->l == NULL)
    {
        if(par->r == x)
           par->r = x->r;
        else
           par->l = x->r;
        free(x);
    }
    else 
    {
        if(par->r == x)
           par->r = x->l;
        else
           par->l = x->l;
        free(x);
    }
}
else
{
    printf("Data = %d not found in the tree\n", data);
}

}
int max(int a,int b)
{
return a>b?a:b;
}
height(bTreeNode *root)
{
if(root == NULL) return 0;
return 1 + max(height(root->r), height(root->l));
}
checkForBalance(bTreeNode *root)
{
int r = height(root->r);
int l = height(root->l);
if(r-h>1 ||r-l
}
int main()
{
    bTreeNode * root = NULL;
    insertBTree(&root, 20);
    insertBTree(&root, 10);
    insertBTree(&root, 30);
    insertBTree(&root, 5);
    insertBTree(&root, 15);
    insertBTree(&root, 25);
    insertBTree(&root, 35);
    balanceTree(&root);
    inorder(root);
    printf("\n");
    delete(&root, 20);
    inorder(root);
    printf("\n");
    delete(&root, 10);
    inorder(root);
    printf("\n"); 
    delete(&root, 30);
    inorder(root);
    printf("\n"); 
    delete(&root, 5);
    inorder(root);
    printf("\n");
    delete(&root, 15); 
    delete(&root, 25); 
    delete(&root, 35); 
    delete(&root,20);
    return 0;
}


