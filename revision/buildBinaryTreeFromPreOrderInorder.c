/*
􏰀 Question 61 Please build a binary tree with a pre-order traversal sequence and an in-order traversal sequence. All elements in these two given sequences are unique.
For example, if the input pre-order traversal sequence is {1, 2, 4, 7, 3, 5, 6, 8} and in-order traversal order is {4, 7, 2, 1, 5, 3, 8, 6}, the built tree is shown in Figure 6-13.
*/
#include<iostream>
#include<exception>
using namespace std;

typedef struct BinaryTreeNode
{
    int m_nValue;
    struct BinaryTreeNode *m_pLeft;
    struct BinaryTreeNode *m_pRight;
} BinaryTreeNode;
void inOrder(BinaryTreeNode *root)
{
if(root==NULL)
 return;
inOrder(root->m_pLeft);
printf("%d, ",root->m_nValue);
inOrder(root->m_pRight);
}
void preOrder(BinaryTreeNode *root)
{
if(root == NULL)
  return;
printf("%d, ",root->m_nValue);
preOrder(root->m_pLeft);
preOrder(root->m_pRight);
}
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);
BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {
    if(preorder == NULL || inorder == NULL || length <= 0)
        return NULL;
    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int*
endInorder) {
    // The first number in the pre-order traversal sequence is the root value
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;
    if(startPreorder == endPreorder) {
        if(startInorder == endInorder
            && *startPreorder == *startInorder)
            return root;
        else
        {
          //throw  std::exception("Invalid input.");
          cout<<"Error";
          exit;
        }
    }
    // Get the root value in the in-order traversal sequence
    int* rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
        ++ rootInorder;
    if(rootInorder == endInorder && *rootInorder != rootValue)
    {  
        cout<<"Error 2";
        exit;   
    //     throw std::exception("Invalid input.");
     }
    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    if(leftLength > 0) {
        // Build left subtree
        root->m_pLeft = ConstructCore(startPreorder + 1,
            leftPreorderEnd, startInorder, rootInorder - 1);
    }
    if(leftLength < endPreorder - startPreorder) {
        // Build rigth subtree
        root->m_pRight = ConstructCore(leftPreorderEnd + 1,
            endPreorder, rootInorder + 1, endInorder);
}
    return root;
}
void rotate(BinaryTreeNode** root, BinaryTreeNode ** prev);
void convertToSingleLinkedList(BinaryTreeNode** root)
{
   BinaryTreeNode* temp = *root;
   BinaryTreeNode* prev =NULL;
   while((*root)->m_pLeft!=NULL)
   {
         rotate(root,&prev);
   }
   prev = *root;
   while(temp->m_pRight!=NULL)
   {
   temp = temp->m_pRight;
   while(temp->m_pLeft!=NULL)
   {
       rotate(&temp,&prev);
   }
   }
}

void rotate(BinaryTreeNode** root, BinaryTreeNode ** prev)
{
   BinaryTreeNode *temp = *root;
   BinaryTreeNode *tempPrev =*prev;
   if(*prev!=NULL)
   {
      tempPrev->m_pRight = temp->m_pLeft;
      temp->m_pLeft = tempPrev->m_pRight->m_pRight;
      tempPrev->m_pRight->m_pRight = *root;
      temp = tempPrev->m_pRight;
   }
   else
   {
      temp= (*root)->m_pLeft;
      (*root)->m_pLeft = temp->m_pRight;
      temp->m_pRight = (*root);
      *root = temp; 
   }
}
void convertToDoubleLinkedList(BinaryTreeNode *root)
{
while(root!= NULL && root->m_pRight!=NULL)
{
   root->m_pRight->m_pLeft = root;
   root = root->m_pRight;
}
}
int main()
{
int preorder[8] = {1,2,4,7,3,5,6,8};
int inorder[8] = {4,7,2,1,5,3,8,6};
int length = 8;
BinaryTreeNode* root = Construct(preorder, inorder, length);
inOrder(root);
printf("\n");
preOrder(root);
convertToSingleLinkedList(&root);
convertToDoubleLinkedList(root);
BinaryTreeNode *temp = root;
while(temp!=NULL)
{
printf("%d",temp->m_nValue);
temp= temp->m_pRight;
}
}
