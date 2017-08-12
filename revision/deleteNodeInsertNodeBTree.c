#include<stdio.h>


typedef struct bTreeNode {
    struct bTreeNode *l;
    struct bTreeNode *r;
    int val;
} bTreeNode;
int arrayPath[4] = {0};
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
int arraySum[8] = {0};
int counter =0 ;
void inorder(bTreeNode *root, int sum)
{
static int i = 0;
if(root == NULL)
{
arraySum[counter] = sum;
counter++;
return;
}
else if(root->r== NULL || root->l == NULL)
{
for(int j = 0; j<i; j++)
   printf("%d->",arrayPath[j]);
printf("%d", root->val);
printf("\n");
}
arrayPath[i] = root->val;
i++;
inorder(root->l,sum+root->val);
inorder(root->r,sum+root->val);
i--;
}
void maxOfArraySum ()
{
int max = 0;
for(int i=0;i<8;i++)
{
   if(max<arraySum[i])
    max = arraySum[i];
}
printf("MAx value = %d",max);
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
bTreeNode * findMin(bTreeNode *root)
{
if (root ==NULL)
   return NULL;
while(root->l!= NULL)
{
root = root->l;
}
return root;
}
bTreeNode *findNext(bTreeNode *root,bTreeNode *node)
{
   if(root==NULL|| node==NULL)
      return NULL;
   if(node->r!=NULL)
      return findMin(node->r);
  bTreeNode *par = NULL;
  while(root!=NULL)
  {
      if(node->val > root->val)
      {
       root= root->r;
      } 
      else if(node->val < root->val)
      { 
       par = root;
       root = root->l;
      }
      else
      {
          return par;
      }
  }
}
void parseBothTrees(bTreeNode *root1, bTreeNode *root2)
{
    if(root1==NULL && root2==NULL)
        return;
    else if(root1==NULL && root2 != NULL)
    {
        parseBothTrees(root1, root2->l);
        printf("%d",root2->val);
        parseBothTrees(root1, root2->r);
        return;
    }
    else if(root1!=NULL && root2 == NULL)
    {
        parseBothTrees(root1->l,root2);
        printf("%d", root1->val);
        parseBothTrees(root1->r,root2);
        return;
    }
    bTreeNode *x, *y = findMin(root2);    
    for(x= findMin(root1);(x && y); x= findNext(root1,x))
    {
        for(;y; y= findNext(root2,y))
        {
               if(x->val < y->val)
               { 
                  printf("%d",x->val);
                  break;  
               }
               else
               {
                  printf("%d",y->val);
               }  
        }
    }
    //parseBootTrees(root1->l,root2->l);
    //printf();
}
int main()
{
    bTreeNode * root = NULL, *root2 =NULL;
    insertBTree(&root, 20);
    insertBTree(&root, 10);
    insertBTree(&root, 30);
    insertBTree(&root, 5);
    insertBTree(&root, 15);
    insertBTree(&root, 25);
    insertBTree(&root, 35);
    inorder(root,0);
    insertBTree(&root2, 20);
    insertBTree(&root2, 10);
    insertBTree(&root2, 30);
    insertBTree(&root2, 5);
    insertBTree(&root2, 15);
    insertBTree(&root2, 25);
    insertBTree(&root2, 35);
    printf("\n");
    //inorder(root2,0);

    parseBothTrees(root,root2);
    maxOfArraySum();
    delete(&root, 20);
   //inorder(root);
    printf("\n");
    delete(&root, 10);
   //inorder(root);
    printf("\n"); 
    delete(&root, 30);
   //inorder(root);
    printf("\n"); 
    delete(&root, 5);
   //inorder(root);
    printf("\n");
    delete(&root, 15); 
    delete(&root, 25); 
    delete(&root, 35); 
    delete(&root,20);
    return 0;
}


